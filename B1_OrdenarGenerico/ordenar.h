#ifndef ORDENAR_H
#define ORDENAR_H

#include <iostream>
#include <vector>
#include "tipos.h"

// El mismo algoritmo de insercion de las clases, escrito una sola vez.
// El compilador genera una version por cada tipo con el que se use.
template <typename T>
void ordenar(std::vector<T>& datos) {
    for (size_t i = 1; i < datos.size(); i++) {
        T actual = datos[i];
        entero j = static_cast<entero>(i) - 1;
        while (j >= 0 && datos[j] > actual) {
            datos[j + 1] = datos[j];
            j--;
        }
        datos[j + 1] = actual;
    }
}

template <typename T>
void mostrar(const std::vector<T>& datos) {
    for (size_t i = 0; i < datos.size(); i++) {
        std::cout << datos[i] << " ";
    }
    std::cout << std::endl;
}

#endif
