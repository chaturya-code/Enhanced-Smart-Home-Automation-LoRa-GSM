#include <SPI.h>
#include <LoRa.h>

// LoRa pins
#define SS 5
#define RST 14
#define DIO0 27

// Button pins
#define BTN1 32
#define BTN2 33
#define BTN3 25
#define BTN4 26
#define BTN5 17

// Built-in LED
#define LED_PIN 2

bool load1=false;
bool load2=false;
bool load3=false;
bool load4=false;

void blinkLED()
{
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
}

void sendCommand(int cmd)
{
  LoRa.beginPacket();
  LoRa.print(cmd);
  LoRa.endPacket();

  Serial.print("Sent: ");
  Serial.println(cmd);

  blinkLED();
}

void setup()
{
  Serial.begin(9600);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);
  pinMode(BTN5, INPUT_PULLUP);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  LoRa.setPins(SS, RST, DIO0);


  if (!LoRa.begin(433E6))
  {
    Serial.println("LoRa Init Failed");
    //while (1);
  }

  Serial.println("LoRa Transmitter Ready");

  Serial.println("AT");
delay(1000);
Serial.println("ATE0");
delay(1000);
Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CNMI=2,2,0,0,0");
delay(1000);
}

void loop()
{

  // BUTTON 1
  if(digitalRead(BTN1)==LOW)
  {
    delay(200);
    load1=!load1;

    if(load1) sendCommand(1);
    else sendCommand(2);

    while(digitalRead(BTN1)==LOW);
  }

  // BUTTON 2
  if(digitalRead(BTN2)==LOW)
  {
    delay(200);
    load2=!load2;

    if(load2) sendCommand(3);
    else sendCommand(4);

    while(digitalRead(BTN2)==LOW);
  }

  // BUTTON 3
  if(digitalRead(BTN3)==LOW)
  {
    delay(200);
    load3=!load3;

    if(load3) sendCommand(5);
    else sendCommand(6);

    while(digitalRead(BTN3)==LOW);
  }

  // BUTTON 4
  if(digitalRead(BTN4)==LOW)
  {
    delay(200);
    load4=!load4;

    if(load4) sendCommand(7);
    else sendCommand(8);

    while(digitalRead(BTN4)==LOW);
  }

  // BUTTON 5 → ALL OFF
  if(digitalRead(BTN5)==LOW)
  {
    delay(200);

    load1=false;
    load2=false;
    load3=false;
    load4=false;

    sendCommand(9);

    while(digitalRead(BTN5)==LOW);
  }


  // SERIAL COMMAND FORMAT: $1 $2 $3 ... $9
  if (Serial.available())
  {
    int x=Serial.read();
    Serial.print(x);
    if(x == '$')
    {
      while(!Serial.available());

      char cmdChar = Serial.read();

      if(cmdChar >= '0' && cmdChar <= '9')
      {
        int cmd = cmdChar - '0';
        sendCommand(cmd);
      }
    }
  }

}