#define EVENTS 10

#include <M5Stack.h>
#include "eventList.h"
#include "displayScreens.h" 
#include "buttons.h"
#include "SoftwareSerial.h"

EventList forList = EventList(EVENTS);
EventList againstList = EventList(EVENTS);
EventList discardList = EventList(EVENTS);

SoftwareSerial rfid(3, 1); // RX, TX

const char* question1 = "In this year, Charles I\nbecame the second Stuart\nKing, after the death of\nhis father James I";
const char* question2 = "Soon after his coronation as king, Parliament\nprevented Charles I from\ncollecting Tonnage and\nPoundage for more than oneyear";
const char* question3 = "Charles I needed money\nbefore he could fight withFrance and Spain, so he\nused a Forced Loan to\nraise money from the\nnobility";
const char* question4 = "Five members of the\nnobility took the king to court over their imprison-ment for refusing to pay\nthe Forced Loan, but the\nking won";
const char* question5 = "Parliament was dissolved\nafter it tried to intro-\nduce measures against\nTonnage and Poundage,\nstarting the Personal Rule";
const char* question6 = "Ship Money was introduced for inland towns to raise money during the Personal Rule";
const char* question7 = "The New Book of Common\nPrayer was introduced in\nScotland, causing riots\nthat led to the First\nBishops' War";
const char* question8 = "The Short Parliament was\ncalled to raise money for the Second Bishops' War,\nending the Personal Rule";
const char* question9 = "The Grand Remonstrance wasrejected by Charles duringthe Long Parliament, so\ncalled because it lasted\nlonger than the Short\nParliament";
const char* question10 = "The English Civil Wars\nbegan when Charles raised his standard in Nottingham";

const char* QUESTIONS[EVENTS] = {question1, question2, question3, question4, question5, question6, question7, question8, question9, question10};
const char* DESCRIPTIONS[EVENTS] = {"Coronation", 
                                            "Ton. + Pound.",
                                            "Forced Loan",
                                            "Five Knight's",
                                            "Dissolution",
                                            "Ship Money",
                                            "Common Prayer",
                                            "Short Parl.",
                                            "Long Parl.",
                                            "Civil War"};

const char* allowedTags[10] = {
  "0600B48BC4\0",
  "0600B3E375\0",
  "0600B498C4\0",
  "0600B3BAC2\0",
  "0600B40130\0",
  "0600B4485B\0",
  "0600B63DBB\0",
  "0600B3C469\0",
  "0600B4C521\0",
  "0600B3CC6D\0"
};

int state = 0;

// If a given tag is in the list of allowedTags, returns its index, otherwise returns -1
int tagInEvents(char tag[]){
  tag[10] = '\0';
  for (int i = 0; i < EVENTS; i++){
    if (strncmp(allowedTags[i], tag, 10) == 0){
      return i;
    }
  }
  return -1;
}

// Waits for a tag to be scanned and then returns the index of the tag in allowedTags
int waitForEvent(){
  Serial.println(F("Waiting for event"));
  char val = 0;
  char tagValue[11];
  int readCount = 0;
  while (readCount < 16){
    if (rfid.available() > 0){
      val = rfid.read();
      if (0 < readCount && readCount < 11){
        tagValue[readCount-1] = val;
      }
      readCount++;
    }
  }
  
  Serial.println(F("Got event:"));
  Serial.println(tagValue);

  return tagInEvents(tagValue);
}

// Puts an event into the correct list for displaying
void separate(int event){
  int button = whichButton();
  switch (button){
    case 0:
      if (!forList.itemInList(event)) forList.addEvent(event);
      break;
    case 1:
      if (!discardList.itemInList(event)) discardList.addEvent(event);
      break;
    case 2:
      if (!againstList.itemInList(event)) againstList.addEvent(event);
      break;
    default:
      Serial.println("There was an error.");
      break;
  }
}

void forAgainstDisplay(){
  int forPos = 0;
  int againstPos = 0;
  const char* forDisplays[EVENTS] = {};
  const char* againstDisplays[EVENTS] = {};
  for (int i = 0; i < EVENTS; i++){
    if (forList.itemInList(i)){
      forDisplays[forPos] = DESCRIPTIONS[i];
      forPos++;
    }
    if (againstList.itemInList(i)){
      againstDisplays[againstPos] = DESCRIPTIONS[i];
      againstPos++;
    }
  }
  forAgainst(forDisplays, againstDisplays, forPos, againstPos);
}

void changeSideLogic(int event){
  int newSide = whichButton();
  forList.removeEvent(event);
  againstList.removeEvent(event);
  discardList.removeEvent(event);
  if (newSide == 0) forList.addEvent(event);
  else if (newSide == 1) discardList.addEvent(event);
  else if (newSide == 2) againstList.addEvent(event);
}

void arrayUpdate(int old, int newPos){
  QUESTIONS[old] = QUESTIONS[newPos];
  DESCRIPTIONS[old] = DESCRIPTIONS[newPos];
  allowedTags[old] = allowedTags[newPos];
}

void updateEventLists(int old, int newPos){
  if (forList.itemInList(old)){
    forList.removeEvent(old);
    forList.addEvent(newPos);
  }
  else if(againstList.itemInList(old)){
    againstList.removeEvent(old);
    againstList.addEvent(newPos);
  }
}

void reinsertItem(bool inFor, int listOffset, int eventOffset, int newEvent, const char* question, const char* description, const char* tag){
  if (inFor) forList.addEvent(newEvent+listOffset);
  else againstList.addEvent(newEvent+listOffset);
  QUESTIONS[newEvent+eventOffset] = question;
  DESCRIPTIONS[newEvent+eventOffset] = description;
  allowedTags[newEvent+eventOffset] = tag;
}

void changePlaceLogic(int event){
  int newEvent = waitForEvent();
  whichSide(QUESTIONS[newEvent], DESCRIPTIONS[event]);
  int choice = whichButton();
  const char* question = QUESTIONS[event];
  const char* description = DESCRIPTIONS[event];
  const char* tag = allowedTags[event];
  bool inFor = false;
  if (choice != 1){
    if (forList.itemInList(event)) {
      forList.removeEvent(event);
      inFor = true;
    }
    else if (againstList.itemInList(event)) againstList.removeEvent(event);
  }
                    
  if (choice == 0 && event > newEvent){
    for (int i = event; i > newEvent; i--){
      arrayUpdate(i, i-1);
      updateEventLists(i-1, i);
    }
    reinsertItem(inFor, 0, 0, newEvent, question, description, tag);
  }
  else if (choice == 0 && event < newEvent){
    for (int i = event; i < newEvent; i++){
      arrayUpdate(i, i+1);
      updateEventLists(i+1, i);
    }
    reinsertItem(inFor, 0, -1, newEvent, question, description, tag);
  }
  else if (choice == 2 && event > newEvent){
    for (int i = event; i > newEvent+1; i--){
      arrayUpdate(i, i-1);
      updateEventLists(i-1, i);
    }
    reinsertItem(inFor, 1, 1, newEvent, question, description, tag);
  }
  else if (choice == 2 && event < newEvent){
    for (int i = event; i < newEvent; i++){
      arrayUpdate(i, i+1);
      updateEventLists(i+1, i);
    }
    reinsertItem(inFor, 0, 0, newEvent, question, description, tag);
  }
}

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);

  Serial.begin(9600);
  rfid.begin(9600);
}

void loop() {
  Serial.println("ForList:");
  forList.showList();
  Serial.println("AgainstList:");
  againstList.showList();
  quoteScreen("'Parliament was the main\ncause of disagreements\nbefore the Civil War.'");
  waitOnButton('b');

  // The event separation phase where events are added to for, against, or discard lists
  if (state == 0){
    forAgainstDisplay();
    int event = waitForEvent();
    displayEvent(QUESTIONS[event]);
    separate(event);
    if (forList.getSize()+againstList.getSize()+discardList.getSize() == EVENTS) state++;
  }

  // The argument arrangement phase. Events are automatically in chronological order, but can be arranged
  else if (state == 1){
    int discardPos = 0;
    int argumentPos = 0;
    const char* discardDisplays[EVENTS] = {};
    const char* argumentDisplays[EVENTS] = {};
    int colours[EVENTS] = {};
    for (int i = 0; i < EVENTS; i++){
      if (discardList.itemInList(i)){
        discardDisplays[discardPos] = DESCRIPTIONS[i];
        discardPos++; 
      }
      if (forList.itemInList(i)){
        argumentDisplays[argumentPos] = DESCRIPTIONS[i];
        colours[argumentPos] = GREEN;
        argumentPos++;
      }
      if (againstList.itemInList(i)){
        argumentDisplays[argumentPos] = DESCRIPTIONS[i];
        colours[argumentPos] = RED;
        argumentPos++;
      }
    }
    argumentScreen(discardDisplays, argumentDisplays, colours, discardPos, argumentPos);
    int event = waitForEvent();
    eventChange(QUESTIONS[event]);
    int choice = whichButton();
    switch (choice){
      case 1:
        changeSide(QUESTIONS[event], colours[event]);
        changeSideLogic(event);
        break;
      case 2:
        changePlace(QUESTIONS[event]);
        changePlaceLogic(event);
        break;
    }
  }
}
