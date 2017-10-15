
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"

char token[] = "ezd8p35t92";
char ssid[] = "Redmi";
char password[] = "shramik49";
int lightPin = D3;
int outdoorlightPin = D2;

#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(4);  // attaches the servo on GIO2 to the servo object
  pinMode(lightPin, OUTPUT);
    pinMode(outdoorlightPin, OUTPUT);
  Serial.begin(9600);
  Cayenne.begin(token, ssid, password);
}

void loop() {
  // put your main code here, to run repeatedly:
  Cayenne.run();
}

CAYENNE_IN(V3)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
    myservo.write(70);
  }
  else
  {
    myservo.write(0);
  }
}
CAYENNE_IN(V4)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
    digitalWrite(lightPin, HIGH);
  }
  else
  {
    digitalWrite(lightPin, LOW);
  }
}
CAYENNE_IN(V5)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
    digitalWrite(outdoorlightPin, HIGH);
  }
  else
  {
    digitalWrite(outdoorlightPin, LOW);
  }
}
