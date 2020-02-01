#include <Wire.h>

#include "SparkFun_SCD30_Arduino_Library.h" 

const unsigned short REPORT_INTERVAL = 2500;
const unsigned short CYCLE_INTERVAL = 10;

const unsigned short INTERRUPTION_PIN = 2;
const unsigned short WELLBEING_PIN = A0;

SCD30 scd30;

void setup() {
    Wire.begin();
    Serial.begin(9600);
    scd30.begin(); 
    pinMode(INTERRUPTION_PIN, INPUT);
    pinMode(WELLBEING_PIN, INPUT);
}

void loop() {
    int co2, wellbeing;
    float temp, humid;
    char tempStr[16], humidStr[16], buf[128];
    int interruptDetected = 0;

    // the button must be pressed for at least CYCLE_INTERVAL
    for (int waitedMillis = 0; waitedMillis < REPORT_INTERVAL; waitedMillis += CYCLE_INTERVAL) {
        bool interrupt = digitalRead(INTERRUPTION_PIN);
        delay(CYCLE_INTERVAL);
        interrupt = interrupt && digitalRead(INTERRUPTION_PIN);
        if (interrupt) {
            interruptDetected = 1;
        }
    }

    // scale from 0..1023 to 0..100
    wellbeing = (int)(1023.0 - analogRead(WELLBEING_PIN)) / 1023.0 * 100.0;

    if (scd30.dataAvailable()) {
        co2 = scd30.getCO2();
        temp = scd30.getTemperature();
        humid = scd30.getHumidity();
        dtostrf(temp, 0, 2, tempStr);
        dtostrf(humid, 0, 2, humidStr);
        sprintf(buf, "co2=%d,temp=%s,humid=%s,interrupt=%d,wellbeing=%d\n",
                co2, tempStr, humidStr, interruptDetected, wellbeing);
        Serial.print(buf);
    } else {
        Serial.println("nil");
    }
}
