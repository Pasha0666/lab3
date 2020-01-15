  
#include "MyServo.h"
#define PIN_SERVO 10

const int echoPin = 8;
const int trigPin = 9;
//MyServo myServo(PIN_SERVO);
Servo servo;

int angle;
bool plus;

void setup()
{
  angle = 0;
  servo.attach(PIN_SERVO);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  Serial.begin(115200);
}

void loop() {
  float result = readDist();
  Serial.println(result);
  for (int i = 0;i < 5;i++)
  {
  if (result < 30.0)
    attack();
  else
    stopAttack();
  delay(30);
  }
}

float readDist()
{
  const float speedOfSoundMPerSec = 340.0;
  const float speedOfSoundCmPerUs = speedOfSoundMPerSec / 10000.0;
  return readPulse() * speedOfSoundCmPerUs / 2.0;    
}

void attack()
{
  if (angle > 90 || angle < 0)
    plus = !plus;
      
  if (plus)
    angle += 15;
  else
    angle -= 15;
  servo.write(angle);
}

void stopAttack()
{
  if (angle != 0)
  {
    angle = 0;
    servo.write(0);
  }
}

float readPulse()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  return duration;
}
