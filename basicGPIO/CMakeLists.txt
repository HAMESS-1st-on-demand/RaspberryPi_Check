cmake_minimum_required(VERSION 3.0.0)
project(GpioTest VERSION 0.1.0 LANGUAGES C)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include (CTest)
include (CPack)

enable_testing() # 테스팅 허용
# add_library(pthreadTest pthreadtest.c pthreadtest.h) # your testing 
# target_link_libraries(pthreadTest pthread)
# target_link_libraries(pthreadTest wiringPi)
# target_link_libraries(pthreadTest bcm2835)

# add_executable(Exproj main.c)
# target_link_libraries(Exproj pthreadTest)
# add_test(NAME Test1 COMMAND Exproj)

# add_executable(GPIOTest main.c)

# blink 사용하기 위한 코드
# add_executable(GPIOTest blink.c)
# target_link_libraries(GPIOTest wiringPi)
# target_link_libraries(GPIOTest bcm2835)
# target_link_libraries(GPIOTest pthread)

# ------------------------------------------

# button.c 사용하기 위한 코드
# add_executable(GPIOTest button.c)
# target_link_libraries(GPIOTest wiringPi)
# target_link_libraries(GPIOTest bcm2835)
# target_link_libraries(GPIOTest pthread)

# button_Int.c 위한 코드
add_executable(GPIOTest button_Int.c)
target_link_libraries(GPIOTest wiringPi)
target_link_libraries(GPIOTest bcm2835)
target_link_libraries(GPIOTest pthread)

