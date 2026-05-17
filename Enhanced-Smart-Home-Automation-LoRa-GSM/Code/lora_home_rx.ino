#include <SPI.h>
#include <LoRa.h>

// Relay Pins
#define RELAY1 16
#define RELAY2 17
#define RELAY3 26
#define RELAY4 25

// LoRa Pins (change if different)
#define SS 5
#define RST 14
#define DIO0 27

void setup()
{
  Serial.begin(9600);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  digitalWrite(RELAY1, 1);
  digitalWrite(RELAY2, 1);
  digitalWrite(RELAY3, 1);
  digitalWrite(RELAY4, 1);

  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6))
  {
    Serial.println("LoRa Failed!");
    while (1);
  }

  Serial.println("LoRa Receiver Ready");
}

void processCommand(int cmd)
{
  switch(cmd)
  {
    case 1:
      digitalWrite(RELAY1, 0);
      break;

    case 2:
      digitalWrite(RELAY1, 1);
      break;

    case 3:
      digitalWrite(RELAY2, 0);
      break;

    case 4:
      digitalWrite(RELAY2, 1);
      break;

    case 5:
      digitalWrite(RELAY3, 0);
      break;

    case 6:
      digitalWrite(RELAY3, 1);
      break;

    case 7:
      digitalWrite(RELAY4, 0);
      break;

    case 8:
      digitalWrite(RELAY4, 1);
      
      break;

  
  case 0:
      digitalWrite(RELAY1, 1);
      digitalWrite(RELAY2, 1);
      break;

    case 9:
      digitalWrite(RELAY3, 1);
      digitalWrite(RELAY4, 1);
      break;
  }
}

void loop()
{

  // Serial Command
  if (Serial.available())
  {
    int cmd = Serial.parseInt();
    processCommand(cmd);
  }

  // LoRa Command
  int packetSize = LoRa.parsePacket();
  if (packetSize)
  {
    String incoming = "";
    while (LoRa.available())
    {
      incoming += (char)LoRa.read();
    }

    int cmd = incoming.toInt();
    processCommand(cmd);

    Serial.print("Received: ");
    Serial.println(cmd);
  }

}