#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "OORi8C-V9P1myP6b7BMLM9DELc_oNdYR";
char ssid[] = "nana";
char pass[] = "jayayudha";

WidgetLED led1(V1);

int sensor = D4;

void setup()
{
 
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(sensor,INPUT);
  while(Blynk.connect() == false){
  Serial.println("tidak terdeteksi");
  
    }

}

void loop()
{
  int sensorval = digitalRead(sensor);
  delay(1000);

  if (sensorval == 1){
    led1.on();
  }

  if (sensorval == 0){
    led1.off();
  }

  Blynk.run();
}
