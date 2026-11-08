#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>
#include "Persona.h"
#include "tipos.h"

std::vector<Persona> leer_personas(entero n);
std::string fecha_y_hora_actual();
bool grabar_registro(const std::string& nombre_archivo, const std::vector<Persona>& personas);

#endif
