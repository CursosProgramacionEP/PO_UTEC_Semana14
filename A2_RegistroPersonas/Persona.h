#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include "tipos.h"

class Persona {
private:
    std::string dni;
    std::string nombre;
    entero edad;
    real salario;

public:
    Persona();
    Persona(std::string dni, std::string nombre, entero edad, real salario);

    std::string getDni() const;
    std::string getNombre() const;
    entero getEdad() const;
    real getSalario() const;
};

#endif
