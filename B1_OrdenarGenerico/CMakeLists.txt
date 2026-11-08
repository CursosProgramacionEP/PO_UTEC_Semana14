cmake_minimum_required(VERSION 3.20)
project(B1_OrdenarGenerico)

set(CMAKE_CXX_STANDARD 20)

add_executable(B1_OrdenarGenerico main.cpp
        COrdenar.cpp
        COrdenar.h
        COrdenarEnteros.cpp
        COrdenarEnteros.h
        COrdenarFlotantes.cpp
        COrdenarFlotantes.h
        ordenar.h
        tipos.h
)
