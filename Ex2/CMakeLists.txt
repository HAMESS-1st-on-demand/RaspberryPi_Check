cmake_minimum_required(VERSION 3.0.0)
project(GpioTest VERSION 0.1.0 LANGUAGES C)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include (CTest)
include (CPack)

enable_testing() # 테스팅 허용
add_library(pthreadTest pthreadtest.c pthreadtest.h)
target_link_libraries(pthreadTest pthread)
target_link_libraries(pthreadTest wiringPi)
target_link_libraries(pthreadTest bcm2835)

add_executable(Exproj main.c)
target_link_libraries(Exproj pthreadTest)
add_test(NAME Test1 COMMAND Exproj)
