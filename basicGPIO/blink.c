#include <wiringPi.h>
#include <stdio.h>

int main()
{
    // wiringPi를 사용하기 위한 코드
    wiringPiSetup(); 
    // 0번 핀을 output으로 사용하겠다.
    pinMode(0, OUTPUT);
    printf("Hello!\n");
    for(int i=0;i<10000;++i)
    {
        printf("Loop %d\n", i);
        // 0번 핀 ON.
        digitalWrite(0, HIGH);
        delay(500);
        // 0번 핀 OFF
        digitalWrite(0, LOW);
        delay(500);
    }
    return 0;
}