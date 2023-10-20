#include <wiringPi.h>
#include <stdio.h>   
#include <stdlib.h>
#include <stdint.h>

#define IR_sensor 2
#define LED 17

void setup(){
    wiringPiSetupGpio();
    pinMode(IR_sensor, INPUT);
    pinMode(LED, OUTPUT);
}

int main(){
    setup();

    while(1) {
        if (digitalRead(IR_sensor) == 1){
            digitalWrite(LED, LOW);
        }
        else{
            digitalWrite(LED, HIGH);
            delay(100);
        }
        
        delay(100);
    }   

}