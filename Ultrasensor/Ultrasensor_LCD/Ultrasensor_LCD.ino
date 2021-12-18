
//Ultrasonic sensor echo and trigger pins
#define echoPin 12
#define trigPin 13

//Loading Liquid Crystal Library
#include <LiquidCrystal.h> 

//Creating Liquid Crystal Object called LCD
//11, 9, 2, 3, 4, 5 are the pins on arduino for the rs, rw enable and d4-d7 pins on the lcd
LiquidCrystal LCD(11, 9, 2, 3, 4, 5); 

long duration;
long distance;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  //Tell Arduino to start your 16 column 2 row LCD
  LCD.begin(16,2); 
  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.setCursor(0,0); 
  //Print Message on First Row
  LCD.print("Object Distance:"); 
  
}

void loop() {
  //Loop code

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

   digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // This gives us distance in cm
  distance = (duration/2)*0.0343;

  if(distance > 400 || distance < 2){
    //Serial.println("Out of Range");
    LCD.setCursor(0,1);
    LCD.print("                       ");
    LCD.setCursor(0,1);
    LCD.print("Out of Range");
  }else{
    //Serial.print(distance);
    LCD.setCursor(0,1);
    LCD.print("                       ");
    LCD.setCursor(0,1);
    LCD.print(distance);
    //Serial.println(" cm");
    //LCD.setCursor(0,4);
    LCD.print(" cm");
    // Milliseconds
    delay(500);
  }
  // Milliseconds
  delay(500);
}
