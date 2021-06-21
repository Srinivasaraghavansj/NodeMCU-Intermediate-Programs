#include <ESP8266WiFi.h>
char ssid[] = "D-Link_DIR-615";
char pass[] = "vingyaninno@123$";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(500);
Serial.println("Connecting to... ");
Serial.println(ssid);
delay(500);

WiFi.disconnect();
WiFi.begin(ssid,pass);

Serial.println("");

while(WiFi.status() != WL_CONNECTED)
{
  Serial.print(" . ");
  delay(500);
}

Serial.println("Wifi Successfully Connected to '"+WiFi.SSID()+"'");
Serial.println("IP Address allotted to Node MCU is '"+(String)WiFi.localIP()+"'");
Serial.println("MAC Address of ESP8266 is '"+WiFi.macAddress()+"'");
Serial.println("");
WiFi.printDiag(Serial);

}

void loop() {
  // put your main code here, to run repeatedly:

}
