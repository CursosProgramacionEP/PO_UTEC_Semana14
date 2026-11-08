#include <algorithm>
#include <fstream>
#include <iostream>
#include "lista_numeros.h"

bool leer_lista(const std::string& nombre_archivo, std::vector<entero>& numeros) {
    numeros.clear();

    std::ifstream entrada(nombre_archivo);
    if (!entrada) {
        return false;
    }

    entero cantidad = 0;
    entrada >> cantidad;

    entero valor = 0;
    for (entero i = 0; i < cantidad && entrada >> valor; i++) {
        numeros.push_back(valor);
    }

    entrada.close();
    return true;
}

void ordenar(std::vector<entero>& numeros) {
    std::sort(numeros.begin(), numeros.end());
}

void mostrar(const std::vector<entero>& numeros) {
    for (size_t i = 0; i < numeros.size(); i++) {
        std::cout << numeros[i] << ", ";
    }
    std::cout << std::endl;
}

// Busqueda secuencial: recorre el vector hasta encontrar el valor.
// Devuelve la posicion, o -1 si el valor no esta en la lista.
entero buscar(const std::vector<entero>& numeros, entero valor) {
    for (size_t i = 0; i < numeros.size(); i++) {
        if (numeros[i] == valor) {
            return static_cast<entero>(i);
        }
    }
    return -1;
}
