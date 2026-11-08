cmake_minimum_required(VERSION 3.20)
project(A1_ContadorVocales)

set(CMAKE_CXX_STANDARD 20)

add_executable(A1_ContadorVocales main.cpp
        contador_vocales.cpp
        contador_vocales.h
        tipos.h
)

# El ejecutable busca los archivos de datos en su directorio de trabajo,
# no en la carpeta del codigo fuente.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_BINARY_DIR})
