const int in1Pin = D1;  // L298N IN1
const int in2Pin = D2;  // L298N IN2
const int in3Pin = D5;  // L298N IN3
const int in4Pin = D6;  // L298N IN4

const int enAPin = D7;  // L298N ENA
const int enBPin = D8;  // L298N ENB

const int potPin = A0;  // Potentiometer connected to A0
int motorSpeed = 0;     // Motor speed variable

int btn = D4;
bool state = false;

void setup() {
  Serial.begin(115200);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(enAPin, OUTPUT);
  pinMode(enBPin, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  buttonRead();
  motorSpeed = analogRead(potPin) / 4;  // Read potentiometer value (0-1023) and map it to PWM range (0-255)
  //analogWrite(enAPin, motorSpeed);      // Set motor speed

  Serial.print("Potentiometer Value: ");
  Serial.print(analogRead(potPin));
  Serial.print(", Motor Speed: ");
  Serial.println(motorSpeed);

  if (state) {
    analogWrite(enAPin, motorSpeed);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  } else {
    analogWrite(enBPin, motorSpeed);
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, HIGH);
  }
  delay(100);
}

void buttonRead() {
  if (digitalRead(btn) == LOW) {
    state = !state;
    delay(50);
    while (digitalRead(btn) == LOW)
      ;
  }
}