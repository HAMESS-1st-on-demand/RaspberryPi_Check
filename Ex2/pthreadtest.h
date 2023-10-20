#ifndef PTHREADTEST_H
#define PTHREADTEST_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void* function_A(void* n);
void* function_B(void* n);

#endif PTHREADTEST_H