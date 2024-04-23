/*
   Sensore di pressione
   Futura Academy: https://academy.futuranet.it/
   Webinar 2: Esp32 Futura Demoboard
   Dario Ciceri
   Canale YouTube: https://www.youtube.com/channel/UCuPuHsNjWX7huiztYu9ROQA
   Profilo Instagram: https://www.instagram.com/_dario.ciceri_/
*/

#include "Arduino.h"
#include "Pressure.h"
#include <Wire.h>

#include <BMx280I2C.h>

#define I2C_ADDRESS 0x76

//create a BMx280I2C object using the I2C interface with I2C Address 0x76
BMx280I2C bmp(I2C_ADDRESS);

void Pressure::init() {
  Wire.begin();
  Serial.println("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
  unsigned status;
  status = bmp.begin();
  if (!status) {
    Serial.println("Sensore di pressione non trovato! Controllare bene le connessioni!");
    while(1) delay(100);
  } else
    Serial.println("Sensore di pressione connesso!");

  //reset sensor to default parameters.
  bmp.resetToDefaults();

  //by default sensing is disabled and must be enabled by setting a non-zero
  //oversampling setting.
  //set an oversampling setting for pressure and temperature measurements.
  bmp.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
  bmp.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);
  read();
}

void Pressure::read() {
  if (bmp.measure())    // Check if the measurement is complete
  {

    //wait for the measurement to finish
    Serial.println();
    Serial.print("Prelevo dati sensore di pressione.");
    do
    {
      Serial.print(".");
      //delay(100);
    } while (!bmp.hasValue());
    Serial.println();
    Serial.println("Dati sensore di pressione:");
    temperature = bmp.getTemperature();
    pressure = bmp.getPressure64();
    float a = pressure / 101325;
    float b = 1 / 5.25588;
    float c = pow(a, b);
    c = 1.0 - c;
    c = c / 0.0000225577;
    altitude = c;
    Serial.print(temperature);                    // Display the results
    Serial.print(F("*C   "));
    Serial.print(pressure);
    Serial.print(F("hPa   "));
    Serial.print(altitude);
    Serial.println(F("m"));
  } else {
    Serial.println("Sensore di pressione: errore lettura dati!");
  }
}
