cmake_minimum_required(VERSION 3.16)
project(bulls_and_cows)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    add_executable(bulls_and_cows bulls_and_cows.cpp)
endif()

add_executable(BullsAndCowsRefactored
        BullsAndCowsRefactored.cpp
        BullsAndCowsGame.cpp
        BullsAndCowsTests.cpp)