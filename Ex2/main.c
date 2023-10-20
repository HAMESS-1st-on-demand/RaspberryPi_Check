#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "pthread.h"

int main()
{
    assert(1 == run());
    printf("테스트가 완료되었습니다.\n");
    return 0;
}