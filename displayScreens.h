void displayEvent(const char* question){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(question);
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
