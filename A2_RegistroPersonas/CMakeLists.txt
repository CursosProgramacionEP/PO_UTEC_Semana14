cmake_minimum_required(VERSION 3.20)
project(A2_RegistroPersonas)

set(CMAKE_CXX_STANDARD 20)

add_executable(A2_RegistroPersonas main.cpp
        Persona.cpp
        Persona.h
        registro.cpp
        registro.h
        tipos.h
)
