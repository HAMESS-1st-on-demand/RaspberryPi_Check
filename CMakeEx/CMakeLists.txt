cmake_minimum_required(VERSION 3.0.0)
project(Exproj VERSION 0.1.0 LANGUAGES C)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CTest)
include(CPack)

enable_testing()
# 테스팅 라이브러리 추가
add_library(naiveGPIO naiveGPIO.c naiveGPIO.h)
target_link_libraries(naiveGPIO wiringPi)
target_link_libraries(naiveGPIO bcm2835)

add_executable(Exproj main.c)
target_link_libraries(Exproj naiveGPIO)
add_test(NAME Test1 COMMAND Exproj)
