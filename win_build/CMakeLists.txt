cmake_minimum_required(VERSION 3.0)
set(CMAKE_SYSTEM_NAME Windows)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(EXE_NAME CHRONOMATE-SUITE.exe)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)



project(CHRONOMATE-SUITE VERSION 1.0)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/win)


add_executable(${EXE_NAME}
    ../src/main.cpp
    ../src/TimeTracker.cpp
    ../src/Task.cpp
)


set_target_properties(${EXE_NAME} PROPERTIES
    COMPILE_FLAGS "-m64"
    LINK_FLAGS "-m64"
)



target_include_directories(${EXE_NAME} PRIVATE ../include)
