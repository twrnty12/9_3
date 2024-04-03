cmake_minimum_required(VERSION 3.2)
project(HomeWorkPatterns-3)

set (SOURCES HomeWorkPatterns-3.cpp Log_console.cpp Log_file.cpp
             Log_message.cpp Observed.cpp Observers.cpp)

set (HEADERS Log_comand.h Log_console.h Log_file.h Log_message.h Observed.h Observers.h)

add_executable(HomeWorkPatterns-3 ${SOURCES} ${HEADERS})