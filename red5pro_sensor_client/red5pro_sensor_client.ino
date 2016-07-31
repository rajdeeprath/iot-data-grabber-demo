#include <dht.h>
#include <SPI.h>
#include <Ethernet.h>

#define dht_apin A0 // Analog Pin DHT11 sensor is connected to


// assign a MAC address for the ethernet controller.
// fill in your address here: 
// de:ad:be:ef:fe:ed
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
}; // DUMMY MAC ID

IPAddress ip(192, 168, 1, 115); // local ip
IPAddress myDns(4, 2, 2, 2); // DNS
EthernetClient client;

char server[] = "192.168.1.100"; // RED5PRO IP
int port = 5080; // RED5PRO PORT

dht DHT;

String humidity;
String temp;
String data;
String uri = "/api/v1/applications/data-grabber/invoke?accessToken=";
String accessToken = "xyz123";

void setup() 
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }   
  delay(2000); // give the ethernet module time to boot up:
  
  Ethernet.begin(mac, ip, myDns);
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());

  // prepare endpoint uri
  uri = uri + accessToken;
  Serial.print("Connection endpoint: ");
  Serial.print(uri);
  Serial.println();

  delay(2000);//Wait before accessing Sensor
  Serial.println("DHT11 Humidity & temperature Sensor to Red5pro\n\n");  
}



void loop() 
{
    DHT.read11(dht_apin);

    humidity = String(DHT.humidity);
    temp = String(DHT.temperature);    

    Serial.print("humidity = " + humidity + "%  temperature = " + temp + " C");
    
    data = "";
    data = data + "{\"method\": \"receiveSensorData\",\"parameters\": [\"{\\\"humidity\\\": " + humidity + ",\\\"temperature\\\": " + temp + "}\"]}";

   //Serial.println(data);
   //doPost(data);

  // Serial.println("sleeping");
  delay(5000);//Wait 10 seconds before accessing sensor again.
}



void doPost(String data)
{
   client.stop();

    if (client.connect(server, port)) 
    {
      Serial.println("connecting...");
      
      // send the HTTP POST request:
      client.println("POST " + uri + " HTTP/1.1");
      client.println("Host: 192.168.1.100");
      client.println("User-Agent: Arduino/1.0");
      client.println("Content-Type: application/json;");
      client.println("Connection: close");
      client.print("Content-Length: ");
      client.println(data.length());
      client.println();
      client.println(data);
    } 
    else 
    {
      Serial.println("connection failed");
    }
}
