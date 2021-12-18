#define echoPin 7
#define trigPin 8

long duration;
long distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

   digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // This gives us distance in cm
  distance = (duration/2)*0.0343;

  if(distance > 400 || distance < 2){
    Serial.println("Out of Range");
  }else{
    Serial.print(distance);
    Serial.println(" cm");
    // Milliseconds
    delay(500);
  }
  // Milliseconds
  delay(500);
}
