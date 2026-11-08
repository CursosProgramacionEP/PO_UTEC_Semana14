cmake_minimum_required(VERSION 3.20)
project(A5_ContadorPalabras)

set(CMAKE_CXX_STANDARD 20)

add_executable(A5_ContadorPalabras main.cpp
        contador_palabras_t.cpp
        contador_palabras_t.h
        tipos.h
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_BINARY_DIR})
