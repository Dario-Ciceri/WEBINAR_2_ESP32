/*
   Futura Academy: https://academy.futuranet.it/
   Webinar 2: Esp32 Futura Demoboard
   Dario Ciceri
   Canale YouTube: https://www.youtube.com/channel/UCuPuHsNjWX7huiztYu9ROQA
   Profilo Instagram: https://www.instagram.com/_dario.ciceri_/
*/

#include "src/FuturaBoard.h"

#define LIGHT_INT_HIGH  1000
#define LIGHT_INT_LOW   10

#define PROX_INT_HIGH   50
#define PROX_INT_LOW    0

OLED display;
AQS sensoreAria;
Gesture sensoreGesture(LIGHT_INT_HIGH, LIGHT_INT_LOW, PROX_INT_HIGH, PROX_INT_LOW, &display);
Lightning sensoreFulmini;
Pressure sensorePressione;
RFID sensoreNfc;

void interruptRoutine() {
  sensoreGesture.isr_flag = 1;
}

void setup() {
  Serial.begin(115200);
  attachInterrupt(sensoreGesture.intPin, interruptRoutine, FALLING);
  printLogo();
  display.init();
  display.show3dCube();
  display.logo();
  display.clear();
  display.displayText(0, 15, "Caricamento...");
  display.clear();
  display.displayText(0, 15, "pressione...");
  sensorePressione.init();
  display.clear();
  display.displayText(0, 15, "AQS...");
  sensoreAria.init();
  display.clear();
  display.displayText(0, 15, "Gestures...");
  sensoreGesture.init();
  display.clear();
  display.displayText(0, 15, "Fulmini...");
  sensoreFulmini.init();
  display.clear();
  display.displayText(0, 15, "NFC...");
  sensoreNfc.init();
  display.clear();
  display.displayText(0, 15, "Fatto!");
  delay(1500);
  display.clear();
}

void loop() {
  //sensorePressione.read();
  //sensoreAria.read();
  //sensoreGesture.handleGesture();
  //sensoreFulmini.read();
  //sensoreNfc.writeMultipleRecords();
  //sensoreNfc.read();
  //delay(3000);
}

void printLogo() {
  for (int i = 0; i < 50; i++) {
    Serial.println();
  }
  Serial.println(" ______     _                                           _                      ");
  Serial.println("|  ____|   | |                       /\\                | |                     ");
  Serial.println("| |__ _   _| |_ _   _ _ __ __ _     /  \\   ___ __ _  __| | ___ _ __ ___  _   _ ");
  Serial.println("|  __| | | | __| | | | '__/ _` |   / /\\ \\ / __/ _` |/ _` |/ _ \\ '_ ` _ \\| | | |");
  Serial.println("| |  | |_| | |_| |_| | | | (_| |  / ____ \\ (_| (_| | (_| |  __/ | | | | | |_| |");
  Serial.println("|_|   \\__,_|\\__|\\__,_|_|  \\__,_| /_/    \\_\\___\\__,_|\\__,_|\\___|_| |_| |_|\\__, |");
  Serial.println("                                                                          __/ |");
  Serial.println("                                                                         |___/ ");
  Serial.println("Futura Academy: https://academy.futuranet.it/");
  Serial.println("Canale YouTube: https://www.youtube.com/channel/UCuPuHsNjWX7huiztYu9ROQA");
  Serial.println("Profilo Instagram: https://www.instagram.com/_dario.ciceri_/");
  Serial.println("Versione Firmware: " + String(__DATE__) + " " + String(__TIME__));
  delay(3000);
}
