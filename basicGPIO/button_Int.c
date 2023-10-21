#include <stdio.h>
#include <wiringPi.h>

char flag = 0, State=0;
// The function will be called when the interrupt triggers.
void myInterrupt()
{
    flag++; // ISR이다. 플래그만 세워줬다
}
 
int main()
{
    // wiringPi를 사용하기 위한 코드
    if(wiringPiSetup() < 0)return 1;
    pinMode(0, OUTPUT);
    // 인터럽트 설정
    if(wiringPiISR(28, INT_EDGE_FALLING, &myInterrupt) < 0)
    {  
        printf("Unable to setup ISR \n");
    }  
    printf("Interrupt test program\n");
    while(1)
    {  
        // 여기서 ISR 처리를 진행한다
        if(flag)
        {  
            while(digitalRead(28) == 0);
            printf("Button On!\n");
            if(State == 1)State = 0;
            else State = 1;
            flag = 0;
        }  
        if(State == 1)digitalWrite(0, HIGH);
        else digitalWrite(0, LOW);
    }  
    return 0;
}