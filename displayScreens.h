void displayEvent(const char* question){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(question);
  M5.Lcd.setCursor(0, 200);
  M5.Lcd.printf("Press the middle button\nwhen ready to continue...");
}
