#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(D3, D2); // RX, TX
#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
unsigned long lastMillis = 0;
int x;
// WiFi network info.
char ssid[] = "Redmi";
char wifiPassword[] = "shramik49";



char username[] = "1e6889a0-a8a0-11e6-a85d-c165103f15c2";
char password[] = "0a7443db1f633b13a06d00adea16f34e1b14f1d2";
char clientID[] = "30eb2ef0-add8-11e7-b177-579293954599";

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  Serial.println("connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  Cayenne.loop();
}
CAYENNE_IN(1)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
    mp3_play();  //Play the first mp3
    Serial.println("playing");
  }
}
CAYENNE_IN(2)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
   mp3_next ();    //play next
    Serial.println("playing next");
  }
}
CAYENNE_IN(3)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
   mp3_prev ();    //play previous
    Serial.println("playing previous");
  }
}
CAYENNE_IN(4)
{
  int currentValue = getValue.asInt();
  if (currentValue == 1)
  {
   mp3_stop ();    //play previous
    Serial.println("playing previous");
  }
}
CAYENNE_IN(5)
{
  int vol = getValue.asInt();
   mp3_set_volume (vol);  //0~30
    Serial.println("volume");
 
}

