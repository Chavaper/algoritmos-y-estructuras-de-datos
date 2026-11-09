cmake_minimum_required(VERSION 4.3)
project(avldraft)

set(CMAKE_CXX_STANDARD 20)

add_executable(avldraft main.cpp
        Nodo.cpp
        Nodo.h
        Elemento.cpp
        Elemento.h
        Utils.h)
