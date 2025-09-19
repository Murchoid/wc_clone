cmake_minimum_required(VERSION 3.28.1)
project(wc_clone C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(wc_clone
    src/main.c
    src/wc.c
)
