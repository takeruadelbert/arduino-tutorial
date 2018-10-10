#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress my_ip(192,168,1,75);
IPAddress server(192,168,1,201);

EthernetClient client;

String params;
StaticJsonBuffer<200> jsonBuffer;

void setup() {
  int monitor_serial = 9600;
  Serial.begin(monitor_serial);

  // wait for serial port to connect
  while(!Serial) {
    
  }

  Ethernet.begin(mac, my_ip);

  params = "value1=";
  params.concat(5);
  params.concat("&value=");
  params.concat(10);

  // parse String to JSON Object
  JsonObject& root = jsonBuffer.createObject();
  root["value"] = 5;
  root["value2"] = 10;

  // this is example for creating nested array data
//  JsonArray& data = root.createNestedArray("data");
//  data.add(123);
//  data.add(321);

  // this is for printing json encoded to serial
  // root.printTo(Serial);

  Serial.print("My IP Address : ");
  Serial.println(my_ip);
  Serial.print("Destination Server : ");
  Serial.println(server);
  Serial.println("Connecting ...");
  delay(3000);

  // connect to server with standard port 80
  if(client.connect(server,80)) {
    Serial.println("Connected.");
    Serial.println();
    delay(1000);

    Serial.println("Sending Data ...");

    // write http request
    client.println("POST /epass-passenger/api/post HTTP/1.1");
    Serial.println("POST /epass-passenger/api/post HTTP/1.1");
    client.print("Host : ");
    client.println(server);
    client.println("Content Type : application/x-www-form-urlencoded");
    client.println("Connection : close");
    client.println("User-Agent : Arduino/1.0");
    client.print("Content-Length : ");
    client.println(root.measureLength());
    client.println();
    Serial.print("Sent Data : ");
    root.printTo(client);
    root.printTo(Serial);
    client.println();
    Serial.println();
  } else {
    Serial.print("Cannot connect to ");
    Serial.println(server);
  }
}

void loop() {
  if(client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  
  if(!client.connected()) {
    Serial.println();    
    Serial.println("Disconnecting ...");
    delay(3000);
    client.stop();
    Serial.println("Disconnected.");
    while(true) {
      delay(1);
    }        
  }  
}
