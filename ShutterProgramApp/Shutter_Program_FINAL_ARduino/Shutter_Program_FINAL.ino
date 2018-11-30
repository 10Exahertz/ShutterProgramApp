#define slot1 23
#define slot2 25
#define slot3 29
#define slot4 33
#define slot5 37
#define slot6 41
#define slot7 45
#define slot8 49

#define INTERRUPTPIN 2

#define s 1
#define t 2
#define u 3
#define v 4
#define w 5
#define x 6
#define y 7
#define z 8
#define r 0

int command;
bool forcestop = false;
char cellspin[8] = {slot1, slot2, slot3, slot4, slot5, slot6, slot7, slot8};
bool cellsonoff[8] = {false, false, false, false,false, false, false, false};

void setup() {
  for (int i = 0; i < 8 ; i++) {
    pinMode(cellspin[i], OUTPUT);
    digitalWrite(cellspin[i], HIGH);//for shutter program this is HIGH
  }

  // initialize the serial communication:
  Serial.begin(9600);

pinMode(INTERRUPTPIN, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(INTERRUPTPIN), emergencystop, CHANGE);
}


void opencell(int cell) {
  if (!forcestop) {
    Serial.print(cell);
    Serial.write(" - open \n");
    digitalWrite(cellspin[cell - 1], LOW);//for shutter program this is LOW
    cellsonoff[cell - 1] = true;
  }
}

void closecell(int cell) {
  if (!forcestop) {
    Serial.print(cell);
    Serial.write(" - close \n");
    digitalWrite(cellspin[cell - 1], HIGH);//for shutter program this is HIGH
    cellsonoff[cell - 1] = false;
  }
}


void emergencystop() {
  for (int i = 0; i < 8 ; i++) {
    pinMode(cellspin[i], OUTPUT);
    digitalWrite(cellspin[i], HIGH);//for shutters high
  }
  forcestop = true;
  Serial.write("Emergency stop! \n");
}

void normalstop() {
  for (int i = 0; i < 8 ; i++) {
    pinMode(cellspin[i], OUTPUT);
    digitalWrite(cellspin[i], HIGH);//for shutters HIGH
  }
  Serial.write("Stop! \n");
}

void waitforseconds(double seconds) {
  while (seconds > 100.0) {
    delay(100.0 * 1000);
    seconds -= 100.0;
  }
  delay(seconds * 1000);
}


void loop() {
  //Contact
  if(Serial.available()){
    char command = Serial.read();
    int loopsn = Serial.parseInt();
    char firstledcolor = Serial.read();
    int firsttime = Serial.parseInt();
    char firstsecondcolor = Serial.read();
    int firstsecondtime = Serial.parseInt();
    char firstthirdcolor = Serial.read();
    int firstthirdtime = Serial.parseInt();
    char firstfourthcolor = Serial.read();
    int firstfourthtime = Serial.parseInt();
    char secondled = Serial.read();
    int secondtime = Serial.parseInt();
    char secondsecondled = Serial.read();
    int secondsecondtime = Serial.parseInt();
    char secondthirdled = Serial.read();
    int secondthirdtime = Serial.parseInt();
    char secondfourthled = Serial.read();
    int secondfourthtime = Serial.parseInt();
    char thirdled = Serial.read();
    int thirdtime = Serial.parseInt();
    char thirdsecondled = Serial.read();
    int thirdsecondtime = Serial.parseInt();
    char thirdthirdled = Serial.read();
    int thirdthirdtime = Serial.parseInt();
    char thirdfourthled = Serial.read();
    int thirdfourthtime = Serial.parseInt();
    char fourthled = Serial.read();
    int fourthtime = Serial.parseInt();
    char fourthsecondled = Serial.read();
    int fourthsecondtime = Serial.parseInt();
    char fourththirdled = Serial.read();
    int fourththirdtime = Serial.parseInt();
    char fourthfourthled = Serial.read();
    int fourthfourthtime = Serial.parseInt();
    char fifthled = Serial.read();
    int fifthtime = Serial.parseInt();
    char fifthsecondled = Serial.read();
    int fifthsecondtime = Serial.parseInt();
    char fifththirdled = Serial.read();
    int fifththirdtime = Serial.parseInt();
    char fifthfourthled = Serial.read();
    int fifthhtime = Serial.parseInt();
    char sixled = Serial.read();
    int sixtime = Serial.parseInt();
    char sixsecondled = Serial.read();
    int sixsecondtime = Serial.parseInt();
    char sixthirdled = Serial.read();
    int sixthirdtime = Serial.parseInt();
    char sixfourthled = Serial.read();
    int sixfourthtime = Serial.parseInt();
    char sevenled = Serial.read();
    int seventime = Serial.parseInt();
    char sevensecondled = Serial.read();
    int sevensecondtime = Serial.parseInt();
    char seventhirdled = Serial.read();
    int seventhirdtime = Serial.parseInt();
    char sevenfourthled = Serial.read();
    int sevenfourthtime = Serial.parseInt();
    char eightled = Serial.read();
    int eighttime = Serial.parseInt();
    char eightsecondled = Serial.read();
    int eightsecondtime = Serial.parseInt();
    char eightthirdled = Serial.read();
    int eightthirdtime = Serial.parseInt();
    char eightfourthled = Serial.read();
    int eightfourthtime = Serial.parseInt();
    char nineled = Serial.read();
    int ninetime = Serial.parseInt();
    char ninesecondled = Serial.read();
    int ninesecondtime = Serial.parseInt();
    char ninethirdled = Serial.read();
    int ninethirdtime = Serial.parseInt();
    char ninefourthled = Serial.read();
    int ninefourthtime = Serial.parseInt();
    char tenled = Serial.read();
    int tentime = Serial.parseInt();
    char tensecondled = Serial.read();
    int tensecondtime = Serial.parseInt();
    char tenthirdled = Serial.read();
    int tenthirdtime = Serial.parseInt();
    char tenfourthled = Serial.read();
    int tenfourthtime = Serial.parseInt();
    Serial.println(loopsn);
    //WORK AROUND CHANGIND THE COMMAND INTO THE RECIPE LOOP
    if (command == 'g'){
      Serial.write("Contact 1\n");
      Serial.write(loopsn);
      Serial.write("Active region\n");
      for (int loops = 0; loops < loopsn; loops++) {
        if (forcestop) break;

        Serial.write("Loop:");
        Serial.print(loops);
        Serial.write("\n");

    //InAlAs 100A
   
        if(loopsn > 0){
          opencell(firstledcolor-'r');
          opencell(firstsecondcolor-'r');
          opencell(firstthirdcolor-'r');
          opencell(firstfourthcolor-'r');
          waitforseconds(firsttime);
          closecell(firstthirdcolor-'r');
          closecell(firstsecondcolor-'r');
          closecell(firstfourthcolor-'r');
          closecell(firstledcolor-'r');
          if(loopsn > 0){
            opencell(secondled-'r');
            opencell(secondsecondled-'r');
            opencell(secondthirdled-'r');
            opencell(secondfourthled-'r');
            waitforseconds(secondtime);
            closecell(secondled-'r');
            closecell(secondsecondled-'r');
            closecell(secondthirdled-'r');
            closecell(secondfourthled-'r');
              if(loopsn > 0){
                opencell(thirdled-'r');
                opencell(thirdsecondled-'r');
                opencell(thirdthirdled-'r');
                opencell(thirdfourthled-'r');
                waitforseconds(thirdtime);
                closecell(thirdled-'r');
                closecell(thirdsecondled-'r');
                closecell(thirdthirdled-'r');
                closecell(thirdfourthled-'r');
                  if(loopsn > 0){
                    opencell(fourthled-'r');
                    opencell(fourthsecondled-'r');
                    opencell(fourththirdled-'r');
                    opencell(fourthfourthled-'r');
                    waitforseconds(fourthtime);
                    closecell(fourthled-'r');
                    closecell(fourthsecondled-'r');
                    closecell(fourththirdled-'r');
                    closecell(fourthfourthled-'r');
                      if(loopsn > 0){
                      opencell(fifthled-'r');
                      opencell(fifthsecondled-'r');
                      opencell(fifththirdled-'r');
                      opencell(fifthfourthled-'r');
                      waitforseconds(fifthtime);
                      closecell(fifthled-'r');
                      closecell(fifthsecondled-'r');
                      closecell(fifththirdled-'r');
                      closecell(fifthfourthled-'r');
                        if(loopsn > 0){
                        opencell(sixled-'r');
                        opencell(sixsecondled-'r');
                        opencell(sixthirdled-'r');
                        opencell(sixfourthled-'r');
                        waitforseconds(sixtime);
                        closecell(sixled-'r');
                        closecell(sixsecondled-'r');
                        closecell(sixthirdled-'r');
                        closecell(sixfourthled-'r');
                          if(loopsn > 0){
                            opencell(sevenled-'r');
                            opencell(sevensecondled-'r');
                            opencell(seventhirdled-'r');
                            opencell(sevenfourthled-'r');
                            waitforseconds(seventime);
                            closecell(sevenled-'r');
                            closecell(sevensecondled-'r');
                            closecell(seventhirdled-'r');
                            closecell(sevenfourthled-'r');
                              if(loopsn > 0){
                                opencell(eightled-'r');
                                opencell(eightsecondled-'r');
                                opencell(eightthirdled-'r');
                                opencell(eightfourthled-'r');
                                waitforseconds(eighttime);
                                closecell(eightled-'r');
                                closecell(eightsecondled-'r');
                                closecell(eightthirdled-'r');
                                closecell(eightfourthled-'r');
                                  if(loopsn > 0){
                                    opencell(nineled-'r');
                                    opencell(ninesecondled-'r');
                                    opencell(ninethirdled-'r');
                                    opencell(ninefourthled-'r');
                                    waitforseconds(ninetime);
                                    closecell(nineled-'r');
                                    closecell(ninesecondled-'r');
                                    closecell(ninethirdled-'r');
                                    closecell(ninefourthled-'r');
                                      if(loopsn > 0){
                                        opencell(tenled-'r');
                                        opencell(tensecondled-'r');
                                        opencell(tenthirdled-'r');
                                        opencell(tenfourthled-'r');
                                        waitforseconds(tentime);
                                        closecell(tenled-'r');
                                        closecell(tensecondled-'r');
                                        closecell(tenthirdled-'r');
                                        closecell(tenfourthled-'r');
                      
          }
                      
          }
                      
          }
                      
          }
                      
          }
                      
          }
          }
          }
          }
       }
     }

  if (forcestop) return;

  Serial.write("Contact 2\n");
      }else if (command == 's'){
      opencell('s'-'r');
      return;
      }
    else if (command == 'f') {
      closecell('s'-'r');
      return;
    }else if (command == 'p'){
      opencell('w'-'r');
      return;
      }
    else if (command == 'c') {
      closecell('w'-'r');
      return;
    }else if (command == 'x'){
      opencell('t'-'r');
      return;
      }
    else if (command == 'z') {
      closecell('t'-'r');
      return;
    }else if (command == 'd'){
      opencell('u'-'r');
      return;
      }
    else if (command == 'q') {
      closecell('u'-'r');
      return;
    }else if (command == 'l'){
      opencell('x'-'v');
      return;
      }
    else if (command == 'm') {
      closecell('x'-'v');
      return;
    }else if(command == 'n'){
      emergencystop();
      return;
      }






  }
}
