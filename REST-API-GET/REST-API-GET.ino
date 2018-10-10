#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress my_ip(192,168,1,75);
IPAddress server(192,168,1,201);

EthernetClient client;

void setup() {
  int monitor_serial = 9600;
  Serial.begin(monitor_serial);

  // wait for serial port to connect
  while(!Serial) {
    ;
  }

  Ethernet.begin(mac, my_ip);

  Serial.print("My IP Address : ");
  Serial.println(my_ip);  
  Serial.print("Destination Server : ");
  Serial.println(server);
  Serial.println("Connecting ...");
  delay(3000);

  // connect to server with standard port 80
  if(client.connect(server, 80)) {
    Serial.println("Connected to server.");
    Serial.println();
    delay(1000);
    Serial.println("Requesting Data from server ...");
//    client.println("GET /epass-passenger/api/test?data=5 HTTP/1.1");
//    Serial.println("GET /epass-passenger/api/test?data=5 HTTP/1.1");
    client.print("GET /epass-passenger/api/test?");
    Serial.print("GET /epass-passenger/api/test?");
    client.println(" HTTP/1.1");
    Serial.println(" HTTP/1.1");
    client.print("Host : ");
    client.println(server);
    client.println("Content Type : application/x-www-form-urlencoded");
    client.println("Connection : close");
    client.println("User-Agent : Arduino/1.0");
    client.println();
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
