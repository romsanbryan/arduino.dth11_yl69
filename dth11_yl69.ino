#include "DHT.h" // Libreria para sensor DTH11
 
#define DHTTYPE DHT11 // Definimos tipo DHT 11

const int DHTPin = 2;     // Pin de accion
 
DHT dht(DHTPin, DHTTYPE); // Asignamos tipo y pin

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  dht.begin();
}

void loop(){
  // DTH11
   float h = dht.readHumidity(); // Recoge datos de humedad
   float t = dht.readTemperature(); // Recoge datos de temperatura
 
   if (isnan(h) || isnan(t)) { // Si falla el sensor
      Serial.println("Fallos con el sensor DTH-11");
      return;
  }
      // Pintamos datos
   Serial.print("Humedad: ");
   Serial.print(h);
   Serial.println(" %\t");
   Serial.print("Temperatura: ");
   Serial.print(t);
   Serial.println(" *C ");

  // YL-69  
  float ht = analogRead(A0); // Puerto analogico

  if(ht >= 1000) { // Si supera a mil de humedad
    Serial.println("Sensor YL-69 Desconectado");
    return;
  }else {
    Serial.print("Humedad de la tierra: ");
    Serial.println(ht);
  }
  
  Serial.println();
  delay(2000); // Esperamos dos segundos
}

