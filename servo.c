#include <stdlib.h>
#include <wiringPi.h>

int servoPin = 14;

void setup(){
    wiringPiSetupGpio();
    pinMode(servoPin, OUTPUT);
}

void loop(){
    for(int i = 1000; i <= 2000; i++){
        digitalWrite(servoPin, HIGH);
        delayMicroseconds(i);
        digitalWrite(servoPin, LOW);
        delayMicroseconds(10);
    }
    delay(50);
    for(int i = 2000; i > 1000; i--){
        digitalWrite(servoPin, HIGH);
        delayMicroseconds(i);
        digitalWrite(servoPin, LOW);
        delayMicroseconds(10);
    }
    delay(50);
}

int main(){
    setup();
    while(1){
        loop();
    }
    return EXIT_SUCCESS;
}
