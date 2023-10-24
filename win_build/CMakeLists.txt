cmake_minimum_required(VERSION 3.0)
set(CMAKE_SYSTEM_NAME Windows)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(EXE_NAME CHRONOMATE-SUITE)
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

# static linking
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
target_link_libraries(${EXE_NAME} -static-libgcc -static-libstdc++)

# adding the libwinpthread-1.dll library to your project
#add_library(winpthread SHARED IMPORTED)
#set_property(TARGET winpthread PROPERTY IMPORTED_LOCATION <path_to_libwinpthread-1.dll>)

# linking the winpthread library to your executable
#target_link_libraries(${EXE_NAME} winpthread)

target_include_directories(${EXE_NAME} PRIVATE ../include)
