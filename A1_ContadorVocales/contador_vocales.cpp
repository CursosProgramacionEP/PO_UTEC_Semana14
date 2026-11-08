#include <cctype>
#include <fstream>
#include "contador_vocales.h"

caracter vocal_en(entero indice) {
    const caracter vocales[TOTAL_VOCALES] = {'a', 'e', 'i', 'o', 'u'};
    return vocales[indice];
}

// Devuelve la posicion de la vocal dentro del arreglo, o -1 si el caracter
// no es una vocal. Las mayusculas se convierten antes de comparar.
entero indice_de(caracter c) {
    caracter minuscula = static_cast<caracter>(std::tolower(static_cast<unsigned char>(c)));
    for (entero i = 0; i < TOTAL_VOCALES; i++) {
        if (minuscula == vocal_en(i)) {
            return i;
        }
    }
    return -1;
}

// Lectura caracter por caracter: get() devuelve el flujo, y el flujo en una
// condicion vale falso cuando ya no se pudo leer nada mas.
bool contar_vocales(const std::string& nombre_entrada, entero frecuencia[TOTAL_VOCALES]) {
    for (entero i = 0; i < TOTAL_VOCALES; i++) {
        frecuencia[i] = 0;
    }

    std::ifstream entrada(nombre_entrada);
    if (!entrada) {
        return false;
    }

    caracter c;
    while (entrada.get(c)) {
        entero posicion = indice_de(c);
        if (posicion != -1) {
            frecuencia[posicion]++;
        }
    }

    entrada.close();
    return true;
}

bool escribir_frecuencias(const std::string& nombre_salida, const entero frecuencia[TOTAL_VOCALES]) {
    std::ofstream salida(nombre_salida);
    if (!salida) {
        return false;
    }

    salida << "Vocal y frecuencia en el texto:" << std::endl;
    for (entero i = 0; i < TOTAL_VOCALES; i++) {
        salida << vocal_en(i) << ": " << frecuencia[i] << std::endl;
    }

    salida.close();
    return true;
}
