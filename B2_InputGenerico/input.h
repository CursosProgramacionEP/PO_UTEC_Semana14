#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <limits>
#include <string>
#include "tipos.h"

// Una sola plantilla sirve para cualquier tipo que sepa leerse con >>.
// El tipo se indica en la llamada: input<int>("Ingrese dato").
template <typename T>
T input(const std::string& mensaje) {
    T valor = T();
    std::cout << mensaje << ": ";
    std::cin >> valor;
    return valor;
}

// Version especializada para cadenas: con >> solo se leeria una palabra,
// asi que esta lee la linea completa.
template <>
inline std::string input<std::string>(const std::string& mensaje) {
    std::string valor;
    std::cout << mensaje << ": ";
    std::cin >> std::ws;
    std::getline(std::cin, valor);
    return valor;
}

#endif
