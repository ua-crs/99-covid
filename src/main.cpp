/*
    main.cpp - Project 99-covid
    Blink a led for 'tblink' periods
*/

#include <Arduino.h>

#include <DallasTemperature.h>
#include <OneWire.h>

//  Definitions

/*
 *  Defined in plaformio.ini
 *  BLINK_LED   IOport for LED
 *  SERIAL_BAUD Serial baud rate
 *  ONE_WIRE_BUS    IOport for 18B20
 */

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

const int tblink = 1000;

void
setup(void)
{
    pinMode(BLINK_LED, OUTPUT);
    Serial.begin(SERIAL_BAUD);
    // Start the DS18B20 sensor
    sensors.begin();
    digitalWrite(BLINK_LED,OFF_LED);

}

static void
show_temperature(void)
{
    sensors.requestTemperatures();
    Serial.print(sensors.getTempCByIndex(0));
    Serial.println(" ºC");
}

void
loop(void)
{
    digitalWrite(BLINK_LED,ON_LED);
    show_temperature();
    digitalWrite(BLINK_LED,OFF_LED);
    delay(tblink);
}

