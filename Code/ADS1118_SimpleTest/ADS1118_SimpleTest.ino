/*  Prototype code for testing knockoff ADS1118 boards with
 *   knockoff SS49E (OH49E analog linear Hall sensors.
*/

#include <ADS1118.h>
#include <SPI.h>

#define sensor_pin 4

ADS1118 ads(sensor_pin);

void setup() {
  pinMode(sensor_pin, OUTPUT);
  digitalWrite(sensor_pin,HIGH);
  Serial.begin(57600);
  ads.begin();
  ads.setSamplingRate(ads.RATE_128SPS);
  ads.setFullScaleRange(ads.FSR_4096);
  ads.setContinuousMode();
  ads.disablePullup();
}

void loop() {
  Serial.println(String(ads.getADCValue(0b100),10));
  delay(100);
}
