#include <wiringPi.h>
#include <stdio.h>

#define GPIO_PIN        18

int main (void){
    int value=0;

    wiringPiSetupGpio();
    pinMode (GPIO_PIN, INPUT) ;

    while(1){
        value=digitalRead(GPIO_PIN);
        if(value==1) printf("dark\n");
        else if(value==0) printf("bright\n");
        delay(500);
    }

  return 0 ;
}