#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"

char token[] = "ycecubqy15";
char ssid[] = "Salgaonkar";
char password[] = "789456123";

unsigned long lastMillis = 0;
int x;
const int codelength = 6;

const int code[codelength] = {1, 0, 1, 0, 0, 1};

int codecounter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Cayenne.begin(token, ssid, password);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:
  Cayenne.run();
}
CAYENNE_IN(V1)
{
  int currentValue = getValue.asInt();
  if (currentValue == 2)
  {
    if (code[codecounter] == 1)
    {
      codecounter++;
      x = 0;
      Serial.println(codecounter);
      Serial.println("true");
    }
    else
    {
      codecounter = 0;
      Serial.println(codecounter);
      Serial.println("false");

    }
  }
}
CAYENNE_IN(V2)
{
  int currentValue = getValue.asInt();
  if (currentValue == 3)
  {
    if (code[codecounter] == 0)
    {
      codecounter++;
      x = 0;
      Serial.println(codecounter);
      Serial.println("true");
    }
    else
    {
      codecounter = 0;
      x = 1;
      Serial.println(codecounter);
      Serial.println("false");

    }
  }
} CAYENNE_IN(V3)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
    if (code[codecounter] == 1)
    {
      codecounter++;
      x = 0;
      Serial.println(codecounter);
      Serial.println("true");
    }
    else
    {
      codecounter = 0;
      x = 1;
      Serial.println(codecounter);
      Serial.println("false");

    }
  }
}
CAYENNE_IN(V4)
{
  int currentValue = getValue.asInt();
  if (currentValue == 4)
  {
    if (code[codecounter] == 0)
    {
      codecounter++;
      x = 0;
      Serial.println(codecounter);
      Serial.println("true");
    }
    else
    {
      codecounter = 0;
      Serial.println(codecounter);
      x = 1;
      Serial.println("false");

    }
  }
}
CAYENNE_IN(V5)
{
  int currentValue = getValue.asInt();
  if (currentValue == 5)
  {
    if (code[codecounter] == 0)
    {
      codecounter++;
      x = 0;
      Serial.println(codecounter);
      Serial.println("true");
    }
    else
    {
      codecounter = 0;
      x = 1;
      Serial.println(codecounter);
      Serial.println("false");

    }
  }
}
CAYENNE_IN(V6)
{
  int currentValue = getValue.asInt();
  if (currentValue == 3)
  {
    if (code[codecounter] == 1)
    {
      codecounter++;
      x = 0;
      Serial.println(codecounter);
      Serial.println("true");
    }
    else
    {
      codecounter = 0;
      x = 1;
      Serial.println(codecounter);
      Serial.println("false");

    }
  }
}

CAYENNE_OUT(V8)
{
  if (codecounter == (codelength) ) {
    Serial.println("Welcome  home");
    Cayenne.virtualWrite(V8, 1);
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
    digitalWrite(LED_BUILTIN, HIGH);
    codecounter = 0;
    Cayenne.virtualWrite(V8, 0);
  }
}
CAYENNE_OUT(V7)
{
  Cayenne.virtualWrite(V7, x);
}

