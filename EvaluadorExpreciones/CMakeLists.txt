cmake_minimum_required(VERSION 3.13)
project(EvaluadorExpreciones)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(EvaluadorExpreciones
        include/Evaluar.h
        include/PostFija.h
        src/Evaluar.cpp
        src/PostFija.cpp
        main.cpp)
