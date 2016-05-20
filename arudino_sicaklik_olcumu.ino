#include <math.h>
 
void setup()
{
  Serial.begin(9600);
}
 
double Termistor(int Analog_Okuma)
{
  double Sicaklik_Degeri;
  Sicaklik_Degeri = log(((10240000 / Analog_Okuma) - 10000));
  Sicaklik_Degeri = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Sicaklik_Degeri * Sicaklik_Degeri )) * Sicaklik_Degeri );
  Sicaklik_Degeri = Sicaklik_Degeri - 273.15;
  return Sicaklik_Degeri;
}
 
void loop()
{
  int Deger;
  double Sicaklik_Degeri;
  Deger = analogRead(A0);
  Sicaklik_Degeri = Termistor(Deger);
  Serial.println(Sicaklik_Degeri);
  delay(500);
}
