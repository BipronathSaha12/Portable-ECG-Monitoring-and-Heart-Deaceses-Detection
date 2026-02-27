#include "protocentralAds1292r.h"
#include "ecgRespirationAlgo.h"
#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

volatile uint8_t globalHeartRate = 0;
volatile uint8_t globalRespirationRate = 0;

const int ADS1292_DRDY_PIN = 2;
const int ADS1292_CS_PIN = 15;
const int ADS1292_START_PIN = 4;
const int ADS1292_PWDN_PIN = 5;

int16_t ecgWaveBuff, ecgFilterout;
int16_t resWaveBuff, respFilterout;

ads1292r ADS1292R;
ecg_respiration_algorithm ECG_RESPIRATION_ALGORITHM;

int xPos = 0;
int yPos = 0;
int lastYPos = 0;
unsigned long lastHeartRateUpdate = 0;

void setup() {
  delay(2000);

  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE1);
  // Selecting 1Mhz clock for SPI
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  pinMode(ADS1292_DRDY_PIN, INPUT);
  pinMode(ADS1292_CS_PIN, OUTPUT);
  pinMode(ADS1292_START_PIN, OUTPUT);
  pinMode(ADS1292_PWDN_PIN, OUTPUT);

  Serial.begin(57600);
  ADS1292R.ads1292Init(ADS1292_CS_PIN, ADS1292_PWDN_PIN, ADS1292_START_PIN);
  Serial.println("Initialization is done");

  tft.begin();
  tft.setRotation(1); 
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(2);

  tft.setTextColor(TFT_GREEN);
  tft.setCursor(5, 5);
  tft.print("ECG Waveform");

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(5, 25);
  tft.print("Heart Rate: ");

  lastYPos = tft.height() / 2; 
}

void loop() {
  ads1292OutputValues ecgRespirationValues;

  boolean ret = ADS1292R.getAds1292EcgAndRespirationSamples(ADS1292_DRDY_PIN, ADS1292_CS_PIN, &ecgRespirationValues);
  if (ret == true) {
    ecgWaveBuff = (int16_t)(ecgRespirationValues.sDaqVals[1] >> 8); 
    resWaveBuff = (int16_t)(ecgRespirationValues.sresultTempResp >> 8);

    if (ecgRespirationValues.leadoffDetected == false) {
      ECG_RESPIRATION_ALGORITHM.ECG_ProcessCurrSample(&ecgWaveBuff, &ecgFilterout);      
      ECG_RESPIRATION_ALGORITHM.QRS_Algorithm_Interface(ecgFilterout, &globalHeartRate);
      //respFilterout = ECG_RESPIRATION_ALGORITHM.Resp_ProcessCurrSample(resWaveBuff);
      //ECG_RESPIRATION_ALGORITHM.RESP_Algorithm_Interface(respFilterout,&globalRespirationRate);

      yPos = map(ecgFilterout, -1000, 1000, tft.height() - 10, 35);
      tft.drawLine(xPos, lastYPos, xPos + 1, yPos, TFT_BLACK);
      tft.drawLine(xPos, lastYPos, xPos + 1, yPos, TFT_CYAN);
      lastYPos = yPos;
      xPos++;
      if (xPos >= tft.width()) {
        xPos = 0;
        tft.fillScreen(TFT_BLACK);
        tft.setTextColor(TFT_GREEN);
        tft.setCursor(5, 5);
        tft.print("ECG Waveform");

        tft.setTextColor(TFT_WHITE);
        tft.setCursor(5, 25);
        tft.print("Heart Rate: ");
      }

    } else {
      ecgFilterout = 0;
      respFilterout = 0;
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_RED);
      tft.setCursor(tft.width() / 2 - 50, tft.height() / 2);
      tft.print("Leads Off");
    }
  }
  if (millis() - lastHeartRateUpdate > 1000) {
    tft.setTextColor(TFT_WHITE);
    tft.fillRect(110, 25, 50, 16, TFT_BLACK); 
    tft.setCursor(110, 25);
    tft.print(globalHeartRate);
    tft.print(" bpm");
    lastHeartRateUpdate = millis();
  }
}
