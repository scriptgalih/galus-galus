#define lm_1 20
#define lm_2 21

#define dirPin 11
#define stepPin 9
#define dirPin2 12
#define stepPin2 10
#define en1 23
#define en2 22

IntervalTimer myTimer;
boolean pulseState = true;
boolean dirState = false;
volatile unsigned long blinkCount = 0;


boolean is_first = true;
int step_ = 6000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(56700);
  pinMode(lm_1, 0);
  pinMode(lm_2, 0);
  pinMode(en1, 1);
  pinMode(en2, 1);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  digitalWrite(dirPin, dirState);
  digitalWrite(dirPin2, dirState);
  digitalWrite(en1, 0);
  digitalWrite(en2, 0);
  delay(100);
  
  while (digitalRead(lm_1)) {
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(200);
  }
  delay(100);
  while (digitalRead(lm_2)) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(200);
  }

  delay(200);
  dirState = true;
  digitalWrite(dirPin, dirState);
  digitalWrite(dirPin2, dirState);
  myTimer.begin(stepperForward, 125);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(lm_1));
  Serial.print("\t");
  Serial.print(digitalRead(lm_2));
  Serial.print("\t");
  Serial.print(blinkCount);
  Serial.print("\t");
  Serial.println(step_);
}

void stepperForward() {
  if (pulseState == LOW) {
    pulseState = HIGH;
    blinkCount = blinkCount + 1;  // increase when LED turns on
  } else {
    pulseState = LOW;
  }
  digitalWrite(stepPin, pulseState);
  digitalWrite(stepPin2, pulseState);

  if (blinkCount >= step_) {
    if (is_first) {
      is_first = false;
      step_ -= 2000;
    }
    blinkCount = 0;
    if (dirState == LOW) {
      dirState = HIGH;
    } else {
      dirState = LOW;
    }

    digitalWrite(dirPin, dirState);
    digitalWrite(dirPin2, dirState);
    delay(200);

  }
}

void calibrated(){
  
}
