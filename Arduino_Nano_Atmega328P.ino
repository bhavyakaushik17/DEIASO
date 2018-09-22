const int numReadings = 32;
int count = 0;
int readings[numReadings];
float avg = 0.0; //In case of Beta1 int gives diff value
//signed long smoothData[numReadings];
int readIndex = 1;
int starttime;

int inputPin = A0;
int outputPin1 = 3;
int outputPin2 = 5;
int outputPin3 = 4;
int outputPin4 = 6;
int outputPin5 = 7;

/*
#include <SoftwareSerial.h>`  
  
#define rxPin 31                     // define SoftwareSerial rx data pin  
#define txPin 30                     // define SoftwareSerial tx data pin  

SoftwareSerial blueTooth(rxPin, txPin);  // create instance of SoftwareSerial  
*/
void setup() {
  Serial.begin(153600);
/*  blueTooth.begin(4800);            // Start SoftwareSerial
  for (int i = 0; i < numReadings; i++) 
  {
    readings[i] = 0;
  }
*/
  pinMode(outputPin1, OUTPUT);
//  pinMode(outputPin2, OUTPUT);
  digitalWrite(outputPin1, LOW);
//  digitalWrite(outputPin2, LOW);
//  Serial.println("<Arduino is ready>");
}

void loop() {
  readings[readIndex] = analogRead(inputPin);
//  Serial.print(readings[readIndex]);
//  Serial.print(",");

  calcavg();
//  Serial.print(smoothData[readIndex]);
//  Serial.print(",");

  blinkLED();//give output in case of impulse

  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  // Serial.print("\n");
//  delay(1);
}
void calcavg() {
  for (int i = 0; i < numReadings; i++) 
  {
    avg = avg + readings[i];
  }
  // Serial.print(avg);
  //Serial.print(",");
  avg = avg / 32;
}


void blinkLED() {
  Serial.print(abs(readings[readIndex]-avg));
  Serial.print(",");
  Serial.print(0.28*avg);
  Serial.print("\n");
/*      char c;  
     if (Serial.available())  
     {  
       c = Serial.read();   
       Serial.println(c);             // Write the character to the Serial Monitor  
        
       blueTooth.write (c);           // Write the character to Bluetooth  
     }
*/
 
  ++count;
  if (readIndex > 0 && count>=600) {
    if (abs(readings[readIndex]-avg) >= 0.28 * avg)
    {
      digitalWrite(outputPin1, HIGH);
//      digitalWrite(outputPin2, HIGH);
//      digitalWrite(outputPin3, HIGH);
//      digitalWrite(outputPin4, HIGH);
 //     digitalWrite(outputPin5, HIGH);
      delay(80);
      digitalWrite(outputPin1, LOW);      
//      digitalWrite(outputPin2, LOW);      
//      digitalWrite(outputPin3, LOW);      
//      digitalWrite(outputPin4, LOW);      
//      digitalWrite(outputPin5, LOW);
    }
/*
if (Serial.available()> 0) {
    {
      if (Serial.read()=='1')
    { digitalWrite(outputPin1, HIGH);
      delay(500);
      digitalWrite(outputPin1, LOW);
    }
    }
}
} 
*/       
//    if (abs(readings[readIndex]-avg) > 0.1 * avg && abs(readings[readIndex]-avg) < 0.28 * avg)
//    {
//      digitalWrite(outputPin1, HIGH);
//      delay(40);
//      digitalWrite(outputPin1, LOW);      
//  }
 }
}




  
