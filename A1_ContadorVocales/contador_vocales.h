#ifndef CONTADOR_VOCALES_H
#define CONTADOR_VOCALES_H

#include <string>
#include "tipos.h"

// Las cinco vocales se guardan en un arreglo de frecuencias:
// la posicion 0 es la 'a', la 1 la 'e', y asi hasta la 'u'.
const entero TOTAL_VOCALES = 5;

caracter vocal_en(entero indice);
entero indice_de(caracter c);

bool contar_vocales(const std::string& nombre_entrada, entero frecuencia[TOTAL_VOCALES]);
bool escribir_frecuencias(const std::string& nombre_salida, const entero frecuencia[TOTAL_VOCALES]);

#endif
