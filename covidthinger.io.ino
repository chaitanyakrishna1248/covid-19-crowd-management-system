#include<SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "chaitanyakrishna"
#define DEVICE_ID "covid19"
#define DEVICE_CREDENTIAL "mputLduc+yRH"

#define SSID "M RAVIPRASAD"
#define SSID_PASSWORD "27406041"
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

String piezo;int x=0,a,b;int count=0;int threshold=100;int sanitise;

void setup() 
{
  pinMode(D0,INPUT);pinMode(D5,INPUT);pinMode(A0,INPUT);
  Serial.begin(9600);
  thing.add_wifi(SSID, SSID_PASSWORD);
  
 thing["a"] >> [](pson& out){
    out["count"]=digitalRead(D0);
    out["count1"]=digitalRead(D5);
    out["piezo"]=analogRead(A0);
    out["system"]=x;
    out["pie"]=piezo;
  };
}

void loop() 
{
 thing.handle();
  a=digitalRead(D0);sanitise=analogRead(A0);
   if(a==0)
   {  for(b=digitalRead(D5);b==1;b=digitalRead(D5));
      x++;
      count=1;
      delay(1000);
      for(b=digitalRead(D5);b==0;b=digitalRead(D5));
   }
   if(sanitise>threshold && count==1){
    count=0;piezo="Yes";
    delay(500);
   }
   else if(count==1 && sanitise<threshold){
   count=0;piezo="No";
   }
   b=digitalRead(D5);
   if(b==0)
   {  for(a=digitalRead(D0);a==1;a=digitalRead(D0));
      x--;
      delay(1000);
      for(a=digitalRead(D0);a==0;a=digitalRead(D0));      
   } 
 
}
