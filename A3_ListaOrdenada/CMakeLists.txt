cmake_minimum_required(VERSION 3.20)
project(A3_ListaOrdenada)

set(CMAKE_CXX_STANDARD 20)

add_executable(A3_ListaOrdenada main.cpp
        lista_numeros.cpp
        lista_numeros.h
        tipos.h
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_BINARY_DIR})
