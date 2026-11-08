#include "Persona.h"

Persona::Persona() {
    this->dni = "";
    this->nombre = "";
    this->edad = 0;
    this->salario = 0.0f;
}

Persona::Persona(std::string dni, std::string nombre, entero edad, real salario) {
    this->dni = dni;
    this->nombre = nombre;
    this->edad = edad;
    this->salario = salario;
}

std::string Persona::getDni() const {
    return this->dni;
}

std::string Persona::getNombre() const {
    return this->nombre;
}

entero Persona::getEdad() const {
    return this->edad;
}

real Persona::getSalario() const {
    return this->salario;
}
