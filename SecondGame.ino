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

const PROGMEM char* question1a = "King John signs the Magna Carta, protecting barons from illegal imprisonment and laying the foundations of the unwritten British constitution.";
const PROGMEM char* question1b = "The Provisions of Oxford sets up a Council of 24 members which the monarch should govern through, reasserting a provision made in the Magna Carta.";
const PROGMEM char* question1c = "After defeating King Henry III (King John’s son), Simon de Montfort calls a parliament of representatives from across the country, widely regarded as the start of the House of Commons.";
const PROGMEM char* question1d = "One of the first restrictions on voting rights was the introduction of a required minimum annual income of 40 shillings and also the introduction of the first-past-the-post voting system.";
const PROGMEM char* question1e = "The Act of Supremacy grants Henry VIII and his heirs Royal Supremacy (making their laws supreme to those of the church) and makes them the Supreme Head of the Church of England.";
const PROGMEM char* question1f = "Soon after the Act of Supremacy, the Law in Wales Acts combined the administrative systems of Wales and England, effectively making them one country.";
const PROGMEM char* question1g = "King James VI of Scotland inherits the English throne as King James I, joining the monarchies of the two countries for the first time, though they retained separate parliaments for over a century. ";
const PROGMEM char* question1h = "During the reign of James I, the Case of Prohibitions is the first case to decide on the royal prerogative powers of the monarch, starting a centuries long process of controlling royal prerogative.";
const PROGMEM char* question1i = "The Petition of Right, which used Magna Carta as its basis, prevents the monarch from imprisoning citizens without cause, along with setting out other liberties which can’t be infringed.";
const PROGMEM char* question1j = "The English Civil War and the other Wars of the Three Kingdoms cause a great shift in power, with King Charles I being executed and parliament increasing its power.";
const PROGMEM char* question1k = "Further to the Petition of Right, the Habeas Corpus Act prevented unlawful or arbitrary imprisonment and was signed during the reign of Charles II, Charles I’s eldest son.";
const PROGMEM char* question1l = "The Bill of Rights is signed into law, setting out the primacy of Parliament and requiring regular free elections for Parliament following the removal of King James II during the Glorious Revolution.";
const PROGMEM char* question1m = "The Bank of England and Bank of Scotland were created as central banks for the two kingdoms, with the Bank of England becoming the main central bank when the kingdoms were united. ";
const PROGMEM char* question1n = "The Act of Settlement, following on from the Bill of Rights, limits the succession of the crown to Protestants only and established judicial independence.";
const PROGMEM char* question1o = "The Acts of Union formally unite the parliaments of Scotland and England into the Parliament of Great Britain.";
const PROGMEM char* question1p = "Robert Walpole starts leading the government during the reign of George I and is considered the first prime minister, though not an official title.";
const PROGMEM char* question1q = "Further Acts of Union merged the kingdoms of Great Britain and Ireland, making Ireland the last of the kingdoms in the British Isles to join United Kingdom of Great Britain and Ireland.";
const PROGMEM char* question1r = "In the early 19th century, the Great Reform Act was the first act to grant voting rights to a significant number of property owning males. This was later extended by multiple Representation of the People Acts.";
const PROGMEM char* question1s = "Towards the end of the 19th century, the first of the Representation of the People Acts gives voting rights to roughly a third of the male population at the time.";
const PROGMEM char* question1t = "Henry Campbell-Bannerman is the first person to officially hold the title of prime minister.";
const PROGMEM char* question1u = "The first of the Parliament Acts is enacted to limit the powers of the House of Lords, preventing them from vetoing most bills and allowing them to delay bills for a short time.";
const PROGMEM char* question1v = "At the end of World War One, the second Representation of the People Act provides universal suffrage for men over 21 and women over 30, removing most property qualifications.";
const PROGMEM char* question1w = "Between the first and second world wars, the Irish Free State broke away from the United Kingdom of Great Britain and Ireland.";
const PROGMEM char* question1x = "Ten years after the Representation of the People Act, women are given the right to vote on the same grounds as men.";
const PROGMEM char* question1y = "The second of the Parliament Acts reduces the amount of time the House of Lords can delay bills for.";
const PROGMEM char* question1z = "Under Conservative prime minister Edward Heath, the European Communities Act passes, joining the UK with the European Economic Community (EEC), which later became the European Union (EU).";
const PROGMEM char* question1aa = "There are no formal rules on ministerial duties, but the Ministerial Code was introduced by the Major and Blair governments to provide guidelines."; 
const PROGMEM char* question1ab = "The Blair government enacted the Human Rights Act to guarantee in the UK the same rights as those granted by the European Convention on Human Rights, allowing cases to be decided in the UK.";
const PROGMEM char* question1ac = "One of the many changes made by the Blair government, the Devolution Acts provide executive and legislature branches for each of the home nations (excluding England).";
const PROGMEM char* question1ad = "The House of Lords are reformed under the Blair government, reducing the number of hereditary peers from 700 to just 92, the rest of the lords would be appointed by the monarch on the suggestion of the prime minister.";
const PROGMEM char* question1ae = "The Perth Agreement is signed by the Commonwealth realms and prime minister David Cameron, changing the succession of the British crown to absolute primogeniture (allowing older females to inherit before males).";
const PROGMEM char* question1af = "During the Conservative-Liberal Democrat coalition government, the Fixed-term Parliament Acts prevents early general elections, unless by a vote of no confidence or two thirds majority in the House of Commons.";
const PROGMEM char* question1ag = "The Brexit Referendum returns a result of 51.9% in favour of leaving, leading to the greatest constitutional change since the UK joined the EEC (later the EU).";

const PROGMEM char* question2a = "Even before Lehman's failure, a run on the UK bank Northern Rock ocurred, spurred by the announcement that the Bank had applied for a loan from the UK government, after experiencing liquidity shortages due to the drop in value of its MBS. The bank was then nationlised.";
const PROGMEM char* question2b = "The same year Lehman fails, Wachovia is bought by Wells Fargo after losing 1% of its deposits in a silent run";
const PROGMEM char* question2c = "The year of Obama's election, Lehman Borthers declares bankruptcy, caused by heavy involvement in subprime mortgages and excessive dependence on borrowing to buy these mortgages."; 
const PROGMEM char* question2d = "The year of Lehman's failure, and as an early consequence of the crisis, Fannie May and Freddie Mac, the largest mortgage providers in the USA, are nationalised. They were on the brink of bankruptcy due to the housing market failure and their involvement in subprime lending.";
const PROGMEM char* question2e = "After Fannie and Freddie are nationalised, the Troubled Assets Relief Program is announced, which is used to bail out AIG, Bank of America and others, as well as facilitate interbank lending. The last bank bailouts in the US occur a year after Lehman's failure.";
const PROGMEM char* question2f = "At the peak of the US crisis, the year Obma moved into office, unemployment reaches 10%, or double its pre-crisis level. The American Reinvestment Act is successful in returning unemployment to normal levels in the USA. By 2016, unemployment was below its precrisis level";
const PROGMEM char* question2g = "The Greek sovereign debt crisis begns a couple of years after Lehman's failure. The government is unable to bail out its national banks, leading it to demand a loan from the Internatioal Monetary Fund (IMF)";
const PROGMEM char* question2h = "The Volcker rule of the Dodd-Frank Act prohibits investment banks from dealing in securities on their own account. Critics have argued that, although speculative trading generates risk, hedging, another form of securities trading, reduces it.";
const PROGMEM char* question2i = "Shortly after the onset fo the Greek crisis, unemployment in the EU hit 12%, with Greece and Spain above 25%. In 2019, unemployment in the Euroezone was still above its pre-crisis level";
const PROGMEM char* question2j = "Several years into the Eurozone crisis, andseeing that the financial crisis is ongoing in Europe, the European Central Bank (ECB) finally resorts to quantitative easing, a set of unconventional policies to ease interbank and private lending";

//const PROGMEM char* QUESTIONS[EVENTS] = {question1b, question1c, question1e, question1f, question1g, question1h, question1k, question1j, question1p, question1t};
//const char* DESCRIPTIONS[EVENTS] = {"Prov. Oxford", 
//                                            "First Commons",
//                                            "Supremacy Act",
//                                            "Law in Wales",
//                                            "King James",
//                                            "Prohibitions",
//                                            "Petition",
//                                            "Civil War",
//                                            "First PM",
//                                            "Official PM"};

const PROGMEM char* QUESTIONS[EVENTS] = {question2a, question2b, question2c, question2d, question2e, question2f, question2g, question2h, question2i, question2j};
const char* DESCRIPTIONS[EVENTS] = {"Northern Rock", 
                                            "Wachovia",
                                            "Lehman",
                                            "Fannie public",
                                            "TARP",
                                            "US unemp",
                                            "Greek crisis",
                                            "Volcker",
                                            "EU unemp",
                                            "EU QE"};

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
//  quoteScreen("'Without the English Civil War, Parliament would be only an advisory body to the monarch.'");
  quoteScreen("'The financial crisis primarily affected the United States'");
  waitOnButton('b');

  // The event separation phase where events are added to for, against, or discard lists
  if (state == 0){
    forAgainstDisplay();
    int event = waitForEvent();
    while (forList.itemInList(event) || againstList.itemInList(event) || discardList.itemInList(event)){
      event = waitForEvent();
    }
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
