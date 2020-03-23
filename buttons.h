bool buttonA(){
  M5.update();
  while (!M5.BtnA.wasReleased()){
    if (M5.BtnB.wasReleased()) return false;
    else if (M5.BtnC.wasReleased()) return false;
    else M5.update();
  }
  return true;
}

bool buttonB(){
  M5.update();
  while (!M5.BtnB.wasReleased()){
    if (M5.BtnA.wasReleased()) return false;
    else if (M5.BtnC.wasReleased()) return false;
    else M5.update();
  }
  return true;
}

bool buttonC(){
  M5.update();
  while (!M5.BtnC.wasReleased()){
    if (M5.BtnA.wasReleased()) return false;
    else if (M5.BtnB.wasReleased()) return false;
    else M5.update();
  }
  return true;
} 

void waitOnButton(char button){
  bool finished = false;
  if (button == 'a' || button == 'A'){
    while (!finished) finished = buttonA();
  }
  else if (button == 'b' || button == 'B'){
    while (!finished) finished = buttonB();
  }
  else if (button == 'c' || button == 'C'){
    while (!finished) finished = buttonC();
  }
}

bool mustPressButton(char button){
  bool correct = false;
  if (button == 'a' || button == 'A'){
    correct = buttonA();
  }
  else if (button == 'b' || button == 'B'){
    correct = buttonB();
  }
  else if (button == 'c' || button == 'C'){
    correct = buttonC();
  }
  return correct;
}

bool anyButton(){
  buttonA();
  return true;
}

int whichButton(){
  while (true){
    if (M5.BtnA.wasReleased()) {
      while(M5.BtnA.wasReleased()) M5.update();
      return 0;
    }
    else if (M5.BtnB.wasReleased()) {
      while(M5.BtnB.wasReleased()) M5.update();
      return 1;
    }
    else if (M5.BtnC.wasReleased()) {
      while(M5.BtnC.wasReleased()) M5.update();
      return 2;
    }
    else M5.update();
  }
  return -1;
}
