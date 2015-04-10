#include <SoftwareSerial.h>// import the serial library
#include "pitches.h"

void
horn(){
  // notes in the melody:
  int melody[] = {
    NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4,4,4,4,4 };

  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}



// seting up the input pins of the motors
// right motor
int R1 = 1; 
int R2 = 2;
// left motor
int L1 = 4;
int L2 = 5;

// set up the bluetooth
// RX pn of the bluetooth has to be connected to the 10 pin
// on arduino, and TX to 11
SoftwareSerial Genotronex(10, 11); // RX, TX
int BluetoothData; // the data given from Computer

void go(int s1R,int s2R,int s3L,int s4L) {
  // the go function gets four arguments where
  // sR1 controls first input from the right motor
  // sR2 controls second input from the right motor
  // and analogicaly for the left motor.
  
  // so (sR1, sR2) = (0,1) moves right wheels forward
  // so (sR1, sR2) = (1,0) moves right wheels backward
  // so (sL1, sL2) = (0,1) moves left wheels forward
  // so (sL1, sL2) = (1,0) moves left wheels backward

  // right forward and left backward makes the car turn left
  // right backward and left forward makes the car turn right

  digitalWrite(R1,s1R);
  digitalWrite(R2,s2R);
  digitalWrite(L1,s3L);
  digitalWrite(L2,s4L);
}

void left(){
  go(0,1,1,0); 
}

void right(){
 go(1,0,0,1);
}

void fd(){
 go(0,1,0,1);
}

void bk(){
  go(1,0,1,0); 
}

void arret(){
 go(0,0,0,0); 
}

void fd_left(){
  go(0,1,0,0); 
}

void fd_right(){
 go(0,0,0,1);
}

void bk_left(){
  go(0,0,1,0); 
}

void bk_right(){
 go(1,0,0,0);
}

void setup() {
  // put your setup code here, to run once:
  
    // setup pins for the car motors
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    
    // setup the bluetooth
  Genotronex.begin(9600);
  Genotronex.println("S to stop; B to go back; F to go forward; L to go left; R to go right");

}

void loop() {
  
  if (Genotronex.available())	
  {
  BluetoothData=Genotronex.read();
  // stop the car
  if (BluetoothData=='S'){
    arret(); // stop
  }
  // go back
  if (BluetoothData=='B'){
   bk(); // back
  }
  // go forward
  if (BluetoothData=='F'){
    fd(); // forward
  }
  // go left
  if (BluetoothData=='L'){
    left();
  }
  // go right
  if (BluetoothData=='R'){
    right();
  }
  // go forward left
  if (BluetoothData == 'G'){
     fd_left();
  }
  // go forward right
  if (BluetoothData == 'I'){
    fd_right();
  }
  // go backward left
  if (BluetoothData == 'H'){
     bk_left();
  }
  // go backward right
  if (BluetoothData == 'j'){
    bk_right();
  }
  // horn
  if (BluetoothData == 'V'){
    horn();
  }
 }  
   //delay(100);
}
 
//  // go backward
//  digitalWrite(R1,HIGH);
//  digitalWrite(R2,LOW);
//  
//  delay(5000);
//  
//  // stop
//  digitalWrite(R1,LOW);
//  digitalWrite(R2,LOW);
//
//  delay(1000);
//  
//  // go forward
//  digitalWrite(R1,LOW);
//  digitalWrite(R2,HIGH);
//  
//  delay(2000);
//  
//  // stop
//  digitalWrite(R1,HIGH);
//  digitalWrite(R2,HIGH);
//  
//  delay(10000);
  




