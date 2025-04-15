/*
   Sensore qualità dell'aria
   Futura Academy: https://academy.futuranet.it/
   Webinar 2: Esp32 Futura Demoboard
   Dario Ciceri
   Canale YouTube: https://www.youtube.com/channel/UCuPuHsNjWX7huiztYu9ROQA
   Profilo Instagram: https://www.instagram.com/_dario.ciceri_/
*/

#ifndef AQS_h
#define AQS_h

#include "Arduino.h"

class AQS
{
  public:
    float co2;
    float tvoc;
    float h2;
    float ethanol;
    void init();
    void calibrate();
    void read();
};

#endif
