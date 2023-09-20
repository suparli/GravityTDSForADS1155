#include <EEPROM.h>
#include "GravityTDS.h"
#include <Adafruit_ADS1X15.h>

GravityTDS gravityTds;

float temperature = 25,tdsValue = 0;

void setup()
{
    Serial.begin(115200);
    gravityTds.begin();  //initialization
}

void loop()
{
    int16_t adc1; // 16 bits ADC read of input A0
	adc1 = ads.readADC_SingleEnded(1);
	float voltage = (adc1 * 0.1875)/1000;
	gravityTds.setVoltage(voltage);  // set the temperature and execute temperature compensation
	gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate 
    tdsValue = gravityTds.getTdsValue();  // then get the value
    Serial.print(tdsValue,0);
    Serial.println("ppm");
    delay(1000);
}
