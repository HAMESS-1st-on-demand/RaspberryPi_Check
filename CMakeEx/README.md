# GPIO Check with CMake

### Before enter your code

#### 1. VS code Extension setting
    - CMake
    - C/C++ Extension Pack
    - C/C++
    - CMake Test Explorer
    - CMake Tools
    - MakeFile

#### 2. ```Ctrl + Alt + P``` 또는 ```F1``` > CMake: 빠른 시작
    - 기본 파일 만들기
    - .gitignore에 **/build** 추가
    
#### 3. Test할 라이브러리 헤더 파일 생성

    - EX) naiveGPIO.h
    ```
    #ifndef NAIVEGPIO_H
    #define NAIVEGPIO_H
    #include <wiringPi.h>
    #include <stdio.h>
    #include <stdlib.h>

    int func(); // 라이버러리에서 실행할 함수
    #endif
    ```

    - EX) naiveGPIO.c
    ```
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

        while(j < 100){
            digitalWrite(LED_PIN, HIGH);
            delay(500);
            digitalWrite(LED_PIN, LOW);
            delay(500);
            ++j;
        }

        return 0;
    }
    ```

#### 4. Testing할 코드 생성

    - EX) main.c
    ```
    #include <stdio.h>
    #include <assert.h>
    #include "naiveGPIO.h"

    int main()
    {
        assert(func() == 0);
        printf("모든 테스트가 완성되었습니다\n");
        return 0;
    }
    ```


#### 5. CMakeLists.txt 작성

    ```
        cmake_minimum_required(VERSION 3.0.0)
        project(Exproj VERSION 0.1.0 LANGUAGES C)

        set(CPACK_PROJECT_NAME ${PROJECT_NAME})
        set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

        include(CTest)
        include(CPack)

        enable_testing()
        # 테스팅 라이브러리 추가
        add_library(naiveGPIO naiveGPIO.c naiveGPIO.h)
        target_link_libraries(naiveGPIO wiringPi) # 라이브러리와 연결
        target_link_libraries(naiveGPIO bcm2835) # 라이브러리와 연결

        add_executable(Exproj main.c)
        target_link_libraries(Exproj naiveGPIO)
        add_test(NAME Test1 COMMAND Exproj)
    ```

#### 6. 테스트 실행

- 컴파일 : ```Shift + F5```
- 테스팅 : 좌측 메뉴의 ```테스팅``` 선택 => 프로젝트 진행
