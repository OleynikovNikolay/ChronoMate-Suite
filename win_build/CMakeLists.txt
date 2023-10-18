cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(CHRONOMATE-SUITE VERSION 1.0)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/win)


add_executable(CHRONOMATE-SUITE
    ../src/main.cpp
    ../src/TimeTracker.cpp
    ../src/Task.cpp
)


set_target_properties(CHRONOMATE-SUITE PROPERTIES
    COMPILE_FLAGS "-m64"
    LINK_FLAGS "-m64"
)


if (WIN32)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
endif()


target_include_directories(CHRONOMATE-SUITE PRIVATE ../include)
