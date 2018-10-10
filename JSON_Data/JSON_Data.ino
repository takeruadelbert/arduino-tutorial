#include <ArduinoJson.h>

void setup() {
  DynamicJsonBuffer jsonBuffer;
  
  Serial.begin(9600);
  String response = "{'status':206,'message':'Valid.','data':[]}";
  JsonObject& root = jsonBuffer.parseObject(response);  
  
  int response_status = root["status"];
  String response_message = root["message"];
  String data = root["data"];
  
  Serial.print("status : ");
  Serial.println(response_status);
  Serial.print("message : ");
  Serial.println(response_message);
  Serial.print("data : ");
  Serial.println(data);
}

void loop() {
  // put your main code here, to run repeatedly:

}
