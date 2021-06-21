#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println();

WiFi.disconnect();
delay(1000);

Serial.println(" No. of Networks found: "+(String)WiFi.scanNetworks());
delay(500);

Serial.println(" Here are the SSIDs :\n");

int n=WiFi.scanNetworks();
for(int i=0; i<n ;i++)
{
  Serial.println((String)WiFi.SSID(i));
}

Serial.println("\n Scan Completed...");
}

void loop() {
  // put your main code here, to run repeatedly:

}
