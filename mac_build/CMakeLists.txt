cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CHRONOMATE-SUITE VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/mac)

add_executable(CHRONOMATE-SUITE 
                    ../src/main.cpp
                    ../src/TimeTracker.cpp
                    ../src/Task.cpp)

target_include_directories(CHRONOMATE-SUITE PRIVATE ../include)