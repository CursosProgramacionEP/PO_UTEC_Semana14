#ifndef LISTA_NUMEROS_H
#define LISTA_NUMEROS_H

#include <string>
#include <vector>
#include "tipos.h"

// El primer numero del archivo no es un dato: es la cantidad de datos
// que vienen despues.
bool leer_lista(const std::string& nombre_archivo, std::vector<entero>& numeros);
void ordenar(std::vector<entero>& numeros);
void mostrar(const std::vector<entero>& numeros);
entero buscar(const std::vector<entero>& numeros, entero valor);

#endif
