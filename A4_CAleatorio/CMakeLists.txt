cmake_minimum_required(VERSION 3.20)
project(A4_CAleatorio)

set(CMAKE_CXX_STANDARD 20)

add_executable(A4_CAleatorio main.cpp
        CAleatorio.cpp
        CAleatorio.h
        tipos.h
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_BINARY_DIR})
