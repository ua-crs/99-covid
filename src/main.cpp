/*
    main.cpp - Project 99-covid
    Blink a led for 'tblink' periods
*/

#include <Arduino.h>

//  Definitions

/*
 *  Defined in plaformio.ini
 *  BLINK_LED   IOport for LED
 *  SERIAL_BAUD Serial baud rate
 */

const int tblink = 1000;

void
setup(void)
{
    pinMode(BLINK_LED, OUTPUT);
    Serial.begin(SERIAL_BAUD);
}

void
loop(void)
{
    digitalWrite(BLINK_LED,HIGH);
    Serial.println("on");
    delay(tblink);

    digitalWrite(BLINK_LED,LOW);
    Serial.println("off");
    delay(tblink/2);
}
