#include <ESP8266WiFi.h>
#include <time.h>
#define LED D1
const char* ssid = "D-Link_DIR-615";

int timezone = 7 * 3600;
int dst=0;

const char* password = "vingyaninno@123$";
unsigned char status_led=0;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  Serial.println("new client");
  while(!client.available())
  {
    delay(1);
  }

  configTime(timezone,dst, "pool.ntp.org" , "time.nist.gov");
  Serial.println("Waiting for internet time\n");

  while(!(time(nullptr)))
  {
    Serial.print("  *");
    delay(500);
  }
  Serial.println("\n Time Response Success  \n");


  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

 String Mousecaughttime = (String)(p_tm->tm_mday) + "/" + (String)(int)(p_tm->tm_mon + 1) + "/" + (String)(int)(p_tm->tm_year + 1900) + " " + (String)(p_tm->tm_hour) + ":" + (String)(p_tm->tm_min) + ":" + (String)(p_tm->tm_sec) ;

  Serial.println(Mousecaughttime);
  delay(1000);


  
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  web += "<html>\r\n";
  web += "<body>\r\n";
  web += "<h1>LED Status</h1>\r\n";
  web +="<p>"+Mousecaughttime+"</p>";
  web += "</body>\r\n";
  web += "</html>\r\n";
  
  client.print(web);
}
