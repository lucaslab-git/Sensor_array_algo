#include <Arduino.h>

int sensorvalues[] = {20, 20, 20, 21, 20, 30, 30, 31, 30, 21, 20, 20, 20, 20};
String valuecolor[14];

struct Farbe
{
  int untere_grenze;
  int obere_grenze;
  int referenzwert;
};

struct Farbe schwarz, weiss, gruen;

void berechnung_werte(int neuer_wert, Farbe color) {
  color.referenzwert = (2 * color.referenzwert + neuer_wert) / 3;

  color.untere_grenze = color.referenzwert - 2;
  color.obere_grenze = color.referenzwert + 2;
}

void validierung_werte(Farbe color, String scolor) {
    for (size_t i = 0; i < 14; i++)
    {
     
      if (sensorvalues[i] <= color.obere_grenze && sensorvalues[i] >= color.untere_grenze)
      {
        berechnung_werte(sensorvalues[i], color);
        valuecolor[i] = scolor;
      }
    }
    
    
}

void Ausgabe(){
  for (size_t i = 0; i < 14; i++)
  {
    Serial.print("|" + String(valuecolor[i]));
  }
  
}
void setup() {
  Serial.begin(9600);
  Serial.println("Bekommener Array:");
  for (size_t i = 0; i < 14; i++)
  {
    Serial.print("|" + String(sensorvalues[i]));
  }
  Serial.println("");
  

  schwarz.referenzwert = 30;
  schwarz.untere_grenze = 28;
  schwarz.obere_grenze = 32;

  weiss.referenzwert = 20;
  weiss.untere_grenze = 18;
  weiss.obere_grenze = 22;  

  gruen.referenzwert = 26;
  validierung_werte(weiss, "WW");
  validierung_werte(schwarz, "SS");

  Ausgabe();
 

}

void loop() {
 
  
}