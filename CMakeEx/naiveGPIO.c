#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#define LED_PIN 1

int func()
{
    int j = 0;
    if(wiringPiSetup() == -1)
    {
        printf("WiringPi 초기화 실패 - GPIO 제어 불가\n");
        return -1;
    }

    pinMode(LED_PIN, OUTPUT);

    while(j < 10){
        digitalWrite(LED_PIN, HIGH);
        delay(50);
        digitalWrite(LED_PIN, LOW);
        delay(50);
        ++j;
    }

    return 0;
}