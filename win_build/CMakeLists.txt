cmake_minimum_required(VERSION 3.0)
set(CMAKE_SYSTEM_NAME Windows)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_FIND_ROOT_PATH
   "/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-x86_64/x86_64-w64-mingw32/bin"
)

set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)


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
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
target_link_libraries(${EXE_NAME} -static-libgcc -static-libstdc++ -static)


target_include_directories(${EXE_NAME} PRIVATE ../include)
