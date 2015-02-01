#include <SoftwareSerial.h>// import the serial library

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
  digitalWrite(R1,s1R);
  digitalWrite(R2,s2R);
  digitalWrite(L1,s3L);
  digitalWrite(L2,s4L);
}

void left(){
 go(1,0,0,1); 
}

void right(){
 go(0,1,1,0); 
}

void fd(){
 go(1,0,1,0); 
}

void bk(){
 go(0,1,0,1); 
}

void arret(){
 go(0,0,0,0); 
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
  Genotronex.println("0 to stop; 1 to go back; 2 to go forward; 3 to go left; 4 to go right");

}

void loop() {
  
   if (Genotronex.available()){
BluetoothData=Genotronex.read();
  // stop the car
  if (BluetoothData=='0'){
    arret();
  }
  // go back
  if (BluetoothData=='1'){
   bk();
  }
  // go forward
  if (BluetoothData=='2'){
    fd();
  }
  // go left
  if (BluetoothData=='3'){
    left();
  }
  // go right
  if (BluetoothData=='4'){
    right();
  }
   }  
   delay(100);
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
  




