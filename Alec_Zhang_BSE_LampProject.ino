//libraries
#include <CayenneMQTTESP8266.h>
#include <esp8266wifi.h>
#include <DHT.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr power.h="">
#endif
#define DHTPIN 4 // setting dht11 pin 
#define DHTTYPE DHT11// setting type of the dht 
#define PIN D5 // neopixel pin conected to d5 
#define NUMPIXELS 35 // number of leds in neopixel ring 
#define buzzer D7// set buzzer pin 
DHT dht(DHTPIN, DHTTYPE);// object for dht11
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);// object for neopixel
char ssid[] = "class1";
char password[] = "11111111";
char username[] = "4753aa20-ec10-11ec-9f5b-45181495093e";
char mqtt_password[] = "a835a76148c271f0a2c6031df9281bcc9b348a6e";
char client_id[] = "9ffb2130-ec10-11ec-8c44-371df593ba58";
const int LDRpin = A0;// ldr pin
const int PIRpin = D0;// pir pin
int LDRval = 0;// for reading ldr value
int PIRval = 0;// for reading pir value
int sumPIR = 0;
int temp;// for reading temperature value from dht11
int hum;// for reading humidity value from dht11
int r, g, b; // variables for storing red green and blue led mix values
int Cmode;// variable for storing security mode activate or deactivate
int TURN;// variable for manual mode
int SAFE_MODE;// variable for false safe mode
int currentMillies = 0;
int prevMillies = 0;
int interval = 5000;
int counter = 0;
void setup()
{
  pinMode(LDRpin, INPUT); // .....|
  pinMode(PIRpin, INPUT); //......| Seting sensors and modules input or output
  pinMode(buzzer, OUTPUT); //.....|
  dht.begin();// starting dht11 sensor
  Serial.begin(9600);
  Cayenne.begin(username, mqtt_password, client_id, ssid, password); // starting cayenne
  pixels.begin(); // start neopixel ring
  Serial.println("FIRE FLY BOOTED");
}
void loop()
{
  Cayenne.loop();
  // checking if security mode is active
  if (Cmode == 1)
  {
    burglarMode();// if security mode us active, call burglar mode function
  }
  else if (Cmode < 1) {
    setLight();// if not active then call setlight function
  }
  hum = dht.readHumidity();// storing humidity value to hum variable
  temp = dht.readTemperature(true);//storing temperature value to temp variable
  LDRval = analogRead(A0);// read and store ldr value
  PIRval = digitalRead(PIRpin); // read and store pir value
  Serial.println(sumPIR);
  sumPIR = sumPIR + PIRval;
  Serial.println(" ");
  counter++;
  Serial.println(counter);
  if (counter >= 300) {
    counter = 0;
    sumPIR = 0;
  }
  // send all sensor values to cayenne
  Cayenne.virtualWrite(0, temp);
  Cayenne.virtualWrite(1, hum, TYPE_RELATIVE_HUMIDITY, UNIT_PERCENT);
  Cayenne.virtualWrite(2, LDRval, UNIT_PERCENT);
  Cayenne.virtualWrite(3, PIRval);
  // checking temperature or humidity is in dangerous level
  if (hum > 70 && hum < 30) {
    digitalWrite(buzzer, HIGH);
  }
  if (temp > 90 && temp < 40)
  {
    digitalWrite(buzzer, HIGH);
  }
  // checking false safe mode
  if (SAFE_MODE == 1)
  {
    digitalWrite(buzzer, LOW);
  }
}
void setColor(int red, int green, int blue)
{
  for (int i = 0; i <= NUMPIXELS; i++) // set every led into the color
  {
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); // seting color neopixel
    pixels.show();// activate neopixel
  }
}
void setLight()// checking manual mode active or not
{
  if (TURN == 1)
  {
    manual();
  }
  else
  {
    if (sumPIR > 0)
    {
      setColor(r, g, b);
    }
    else if (LDRval < 30)
    {
      setColor(r, g, b);
    }
    else if (sumPIR < 1 && LDRval > 10 && counter >= 300)
    {      
      setColor(0,0,0);
    }
  }
}
void burglarMode()// burglar mode's function
{
  if (SAFE_MODE == 1)
  {
    digitalWrite(buzzer, LOW);
  }
  if (PIRval > 0)
  {
    digitalWrite(buzzer, HIGH);
    Serial.println("burglar on");
  }
}
void manual()// manual mod's function
{
  setColor(r, g, b);
}
//receive values from cayenne
CAYENNE_IN(4)
{
  r = getValue.asInt(); // receive red value for neopixel from cayenne
}
CAYENNE_IN(5)
{
  g = getValue.asInt(); // receive green value for neopixel from cayenne
}
CAYENNE_IN(6)
{
  b = getValue.asInt(); // receive blue value for neopixel from cayenne
}
CAYENNE_IN(7)
{
  Cmode = getValue.asInt(); // receive commands for security mode
  Serial.println(Cmode);
}
CAYENNE_IN(8)
{
  TURN = getValue.asInt();// receive commands for manual mode
}
CAYENNE_IN(9)
{
  SAFE_MODE = getValue.asInt();// receive commands for false safe
}
