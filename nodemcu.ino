
#include <ESP8266WiFi.h>

//router user name and password
const char* ssid = "test";
const char* password = "abc@1234";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
//int ledPin = D4;
int REDPIN = D1;
int GREENPIN = D2;
int BLUEPIN = D3;

char value;

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  //pinMode(ledPin, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  //digitalWrite(ledPin, LOW);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  if (req.indexOf("/LED_1/on") != -1){
    Serial.println(" Relax Mode         ");
    ColorLamp(211,224,255);  
  }
    
  else if (req.indexOf("LED_2/on") != -1){
    Serial.println(" Read Mode         ");
    ColorLamp(255,234,100);  
  }
  else if (req.indexOf("LED_3/on") != -1){
    Serial.println(" Read Mode         ");
    ColorLamp(53,114,255); 
  }
  else if (req.indexOf("LED_4/on") != -1){
    Serial.println(" Read Mode         ");
    ColorLamp(228,40,255);  
  }
  else if (req.indexOf("LED_5/on") != -1){
    Serial.println(" Read Mode         ");
    ColorLamp(255,51,56); 
  }
  else if (req.indexOf("LED_6/on") != -1){
    Serial.println(" Read Mode         ");
    ColorLamp(191,46,222); 
  }
  else if (req.indexOf("LED_7/on") != -1){
    Serial.println(" Read Mode         ");
    ColorLamp(255,212,29); 
  }
  else if (req.indexOf("LED_8/on") != -1){
    Serial.println(" Read Mode         ");
    ColorLamp(255,246,237);  
  }
  else if (req.indexOf("LED_9/on") != -1){
    Serial.println(" Fish Breeding Mode         ");
    ColorLamp(125,162,255);  
  }
  else if (req.indexOf("LED/on") != -1){
    Serial.println(" on        ");
    ColorLamp(255,255,255);  
  }
  else if (req.indexOf("LED/off") != -1){
    Serial.println(" off         ");
    ColorLamp(0,0,0);  
  }
    
  else if (req.indexOf("/") != -1)
    ; //do nothing; just send html page
  else {
    client.stop();
    return;
  }
  client.flush();
  
  String HTML = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>";
  HTML += "<head><style>";
  HTML += "button{background-color:blue}";
  HTML += "div{width:300px;height:350px;}";
  HTML += "#header{background-color:blue;color:white;padding: 50px 0px;font-size:100px;font-weight:bold;width:100%;height:100px;text-align:center;}";
  HTML += "#one{background-color:rgb(211,224,255);background-size:contain;background-repeat:no-repeat;background-image:url('https://i.ibb.co/F5dyZG9/1.png'); }";
  HTML += "#two{background-color:rgb(255,234,217);background-size:contain;background-repeat:no-repeat;background-image:url('https://i.ibb.co/QMjcq6J/2-person58-80372-min.png'); }";
  HTML += "#three{background-color:rgb(197,215,255);background-size:contain;background-repeat:no-repeat;background-image:url('https://i.ibb.co/zSxWYjt/3-clean-min.png'); }";
  HTML += "#four{background-color:rgb(238,166,231);background-size:contain;background-repeat:no-repeat; background-image:url('https://i.ibb.co/tMKBndf/4-c5989809e0bb7b8c780aa6c4d85c5653-medita-o-budista-representar-cone-by-vexels-min.png');}";
  HTML += "#five{background-color:rgb(255,128,131);background-size:contain;background-repeat:no-repeat; background-image:url('https://i.ibb.co/Jn6fnjQ/5-heart-min.png');}";
  HTML += "#six{background-color:rgb(243,167,241);background-size:contain;background-repeat:no-repeat; background-image:url('https://i.ibb.co/9gNq03K/6-young-people-icon-1-min.png');}";
  HTML += "#seven{background-color:rgb(255,212,029);background-size:contain;background-repeat:no-repeat; background-image:url('https://i.ibb.co/5vPM9Fd/7-zoo-min.png');}";
  HTML += "#eight{background-color:rgb(255,246,237);background-size:contain;background-repeat:no-repeat; background-image:url('https://i.ibb.co/PZf7x8y/8-potted-plant-min.png');}";
  HTML += "#nine{background-color:rgb(221,230,255);background-size:contain;background-repeat:no-repeat; background-image:url('https://i.ibb.co/G7q5N4M/9-fish-755-819239-min.png');}";
  HTML += "#on,#off{width:100%;height:100px;text-align:center;margin:10px;background-color:#DBD6D4;font-size:60px;padding-top:20px;}";
  HTML += "</style></head>";
  HTML += "<body>";
  HTML += "<div id=\"header\">Mode Selector</div>";
  HTML += "<table width=\"100%\" cellpadding=\"1\">";
  HTML += "<tr>";
  HTML += "<td><div id=\"one\" onclick=\"window.location.href='/LED_1/on'\"></div></td>";
  HTML += "<td><div id=\"two\" onclick=\"window.location.href='/LED_2/on'\"></div></td>";
  HTML += "<td><div id=\"three\" onclick=\"window.location.href='/LED_3/on'\"></div></td>";
  HTML += "</tr>";
  HTML += "<tr>";
  HTML += "<td><div id=\"four\" onclick=\"window.location.href='/LED_4/on'\"></div></td>";
  HTML += "<td><div id=\"five\" onclick=\"window.location.href='/LED_5/on'\"></div></td>";
  HTML += "<td><div id=\"six\" onclick=\"window.location.href='/LED_6/on'\"></div></td>";
  HTML += "</tr>";
  HTML += "<tr>";
  HTML += "<td><div id=\"seven\" onclick=\"window.location.href='/LED_7/on'\"></div></td>";
  HTML += "<td><div id=\"eight\" onclick=\"window.location.href='/LED_8/on'\"></div></td>";
  HTML += "<td><div id=\"nine\" onclick=\"window.location.href='/LED_9/on'\"></div></td>";
  HTML += "</tr>";
  HTML += "</table>";
  HTML += "<div id=\"on\" onclick=\"window.location.href='/LED/on'\"><b>ON</b></div>";
  HTML += "<div id=\"off\" onclick=\"window.location.href='/LED/off'\"><b>OFF</b></div>";
  //HTML += "<div id=\"three\"></div>";
  //HTML += " <h1>DIY HowToDoIt</h1> <h2>ESP8266 Web Server</h2>";
  //HTML += "<h3>Blue LED is now ";
  //HTML += (digitalRead(ledPin))?"OFF":"ON</h3>"; //Low = LED ON and High = LED OFF
  //HTML += "<h3>Blue LED <button onclick=\"window.location.href='/LED_1/on'\">LED ON</button>&nbsp;<button onclick=\"window.location.href='/LED_1/off'\">LED OFF</button></h3>";
  //HTML += "<div class=\"a\" onclick=\"window.location.href='/LED_1/on'\"></div>";
  HTML += "</body></html>";
 
  //response as HTML page
  client.print(HTML);
  delay(10);
  
}


void ColorLamp(int R, int G, int B){
     analogWrite(REDPIN, R);
     analogWrite(GREENPIN, G);
     analogWrite(BLUEPIN, B);
}
