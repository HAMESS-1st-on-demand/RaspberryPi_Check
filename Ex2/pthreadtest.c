#ifndef PTHREADHTEST_H
#include "pthread.h"
#endif

void* function_A(void* n){
    int i=0;
    while(i< 100)
    {
        printf("Thread A i = [%3d]\n", i);
        ++i;
        if(i % 5 == 0)delay(10);
    }
    return NULL;
}

void* function_B(void* n){
    int i=0;
    while(i< 100)
    {
        printf("Thread B i = [%3d]\n", i);
        ++i;
        if(i % 3 == 0)delay(10);
    }
    return NULL;
}

int run()
{
    pthread_t pthread_A, pthread_B;
    int cnt = 0;
    printf("Create Thread A\n");
    pthread_create(&pthread_A, NULL, function_A, NULL);
    printf("Create Tread B\n");
    pthread_create(&pthread_B, NULL, function_B, NULL);

    pthread_join(pthread_A, NULL);
    pthread_join(pthread_B, NULL);
    return 1;
}