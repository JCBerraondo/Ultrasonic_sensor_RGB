// Inputs

// RGB inputs
  int ledR= 5;
  int ledG= 6;
  int ledB= 7;
  int red= 0;     //ver si estas variables las nececito mas adelante
  int green= 0;
  int blue= 0;

// Engines inputs
  const int AIA= 3;
  const int AIB= 11;
  const int BIA= 9;
  const int BIB= 10;

// Ultrasonic sensor inputs
  int trigger= 2;
  int echo= 4;
  long timePulse;
  float dstMeasure;

int ledTest= 13;


void setup() {
    // RGB setup
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
       // Turns off
      analogWrite(ledR, 0);
      analogWrite(ledG, 0);
      analogWrite(ledB, 0);

    // Engines setup
    pinMode(AIA, OUTPUT);
    pinMode(AIB, OUTPUT);
    pinMode(BIA, OUTPUT);
    pinMode(BIB, OUTPUT); 
      // Turns off
      analogWrite(AIA, 0);
      analogWrite(AIB, 0);
      analogWrite(BIA, 0);
      analogWrite(BIB, 0);

    // Ultrasonic sensor setup
    Serial.begin(9600);
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
      // Turns off
      digitalWrite(trigger, LOW);
      digitalWrite(ledTest, LOW); 
    
pinMode(ledTest, OUTPUT);

  //inicial greeting
    for(int i=0; i<3; i++){
      digitalWrite(ledTest, HIGH);
      delay(500);
      digitalWrite(ledTest, LOW);
      delay(500);
    }
}

void loop() {
  // Signal triger
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    timePulse= pulseIn(echo, HIGH);
    dstMeasure= 0.0340/2 * timePulse;

      // Conditional
    if(dstMeasure<20){
      analogWrite(ledR, 255);
      analogWrite(ledG, 0);
      analogWrite(ledB, 0);
      right();
      delay(500);
    }
    else if (dstMeasure>= 20 && dstMeasure< 30){
      analogWrite(ledR, 0);
      analogWrite(ledG, 0);
      analogWrite(ledB, 255);
      forward();
      delayMicroseconds(10);
    }
    else if (dstMeasure>=30){
      analogWrite(ledR, 0);
      analogWrite(ledG, 255);
      analogWrite(ledB, 0);
      forward();
      delayMicroseconds(10);
    }
    // Serial monitor
    Serial.println("Distance");
    Serial.println(dstMeasure);
    delay (500);

}

void forward(){
  analogWrite(AIA,130);
  analogWrite(AIB,0);
  analogWrite(BIA,0);
  analogWrite(BIB,130);
}

void back(){
  analogWrite(AIA,0);
  analogWrite(AIB,130);
  analogWrite(BIA,130);
  analogWrite(BIB,0);
}

void right(){
  analogWrite(AIA,130);
  analogWrite(AIB,0);
  analogWrite(BIA,130);
  analogWrite(BIB,0);
}

void left(){
  analogWrite(AIA,0);
  analogWrite(AIB,130);
  analogWrite(BIA,0);
  analogWrite(BIB,130);
}

void stop(){
  analogWrite(AIA,150);
  analogWrite(AIB,150);
  analogWrite(BIA,150);
  analogWrite(BIB,150);
  delay(500);
}