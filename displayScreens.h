void quoteScreen(const char* quote){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("Your quote is:");
  M5.lcd.setCursor(0, 20);
  M5.Lcd.printf(quote);
  M5.Lcd.setCursor(0, 200);
  M5.Lcd.printf("Press the middle button\nwhen ready to continue...");
}

void displayEvent(const char* question){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf(question);
  M5.Lcd.setCursor(50, 220);
  M5.Lcd.setTextColor(GREEN);
  M5.Lcd.printf("FOR");
  M5.Lcd.setCursor(120, 220);
  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.printf("DISCARD");
  M5.Lcd.setCursor(215, 220);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.printf("AGAINST");
  M5.Lcd.setTextColor(WHITE);
}

void eventChange(const char* question){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf(question);
  M5.Lcd.setCursor(50, 220);
  M5.Lcd.printf("BACK");
  M5.Lcd.setCursor(125, 200);
  M5.Lcd.printf("CHANGE");
  M5.Lcd.setCursor(140, 220);
  M5.Lcd.printf("SIDE");
  M5.Lcd.setCursor(220, 200);
  M5.Lcd.printf("CHANGE");
  M5.Lcd.setCursor(225, 220);
  M5.Lcd.printf("PLACE");
}

void changeSide(const char* question, int side){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf(question);

  M5.Lcd.setCursor(0, 180);
  M5.Lcd.setTextColor(side);
  switch (side){
    case GREEN:
      M5.Lcd.printf("Currently FOR");
      break;
    case RED:
      M5.Lcd.printf("Currently AGAINST");
      break;
    case BLUE:
      M5.Lcd.printf("Currently DISCARDED");
      break;
  }
  
  M5.Lcd.setCursor(50, 220);
  M5.Lcd.setTextColor(GREEN);
  M5.Lcd.printf("FOR");
  M5.Lcd.setCursor(120, 220);
  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.printf("DISCARD");
  M5.Lcd.setCursor(215, 220);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.printf("AGAINST");
  M5.Lcd.setTextColor(WHITE);
}

void changePlace(const char* question){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf(question);

  M5.Lcd.setCursor(0, 200);
  M5.Lcd.printf("Scan an event to place\nthis event next to...");
}

void whichSide(const char* question, const char* description){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf(question);
  M5.Lcd.setCursor(0, 160);
  M5.Lcd.printf("Which side would you like to place %s?", description);
  M5.Lcd.setCursor(0, 220);
  M5.Lcd.printf("BEFORE");
  M5.Lcd.setCursor(125, 220);
  M5.Lcd.printf("CANCEL");
  M5.Lcd.setCursor(260, 220);
  M5.Lcd.printf("AFTER");
}

void forAgainst(const char* forList[], const char* againstList[], int forLength, int againstLength){
  // Initialise screen
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);

  // Draw dividing lines
  M5.Lcd.drawLine(160, 0, 160, 200, WHITE);
  M5.Lcd.drawLine(0, 20, 320, 20, WHITE);

  // Write column titles
  M5.Lcd.setCursor(60, 0);
  M5.Lcd.setTextColor(GREEN);
  M5.Lcd.printf("FOR");
  M5.Lcd.setCursor(205, 0);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.printf("AGAINST");

  M5.Lcd.setTextColor(WHITE);

  // Write for and against lists
  int forPos = 25;
  int againstPos = 25;
  for (int i = 0; i < forLength; i++){
    M5.Lcd.setCursor(0, forPos);
    M5.Lcd.printf(forList[i]);
    forPos += 20;
  }
  for (int i = 0; i < againstLength; i++){
    M5.Lcd.setCursor(161, againstPos);
    M5.Lcd.printf(againstList[i]);
    againstPos += 20;
  }

  // Write user prompt
  M5.Lcd.setCursor(0, 210);
  M5.Lcd.printf("Scan an event to add it...");
}

void argumentScreen(const char* discardList[], const char* argumentList[], const int colours[], int discardPos, int argumentPos){
  // Initialise screen
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);

  // Draw dividing lines
  M5.Lcd.drawLine(160, 0, 160, 200, WHITE);
  M5.Lcd.drawLine(0, 20, 320, 20, WHITE);

  // Write column titles
  M5.Lcd.setCursor(30, 0);
  M5.Lcd.setTextColor(GREEN);
  M5.Lcd.printf("ARGUMENT");
  M5.Lcd.setCursor(190, 0);
  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.printf("DISCARDED");

  // Write argument and discarded lists
  int argPos = 25;
  int disPos = 25;
  for (int i = 0; i < argumentPos; i++){
    M5.Lcd.setCursor(0, argPos);
    M5.Lcd.setTextColor(colours[i]);
    M5.Lcd.printf(argumentList[i]);
    argPos += 20;
  }
  M5.Lcd.setTextColor(BLUE);
  for (int i = 0; i < discardPos; i++){
    M5.Lcd.setCursor(161, disPos);
    M5.Lcd.printf(discardList[i]);
    disPos += 20;
  }

  M5.Lcd.setTextColor(WHITE);
  
  // Write user prompt
  M5.Lcd.setCursor(0, 205);
  M5.Lcd.printf("Scan an event to change\nits position...");
}
