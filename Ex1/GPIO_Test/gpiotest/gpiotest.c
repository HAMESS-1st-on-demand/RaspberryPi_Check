#include <stdio.h>
#include <wiringPi.h>

#define LED 0

int main(void){
    if(wiringPiSetup() == -1)
    return 1;

    pinMode(LED, OUTPUT);

    while(1){
        printf("LED HIGH\n");
        digitalWrite (LED, HIGH);
        delay(1000);

        printf("LED LOW\n");
        digitalWrite (LED, LOW);
        delay(1000);
    }
    return 0;

}