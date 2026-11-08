#include <fstream>
#include "contador_palabras_t.h"

contador_palabras_t::contador_palabras_t() {
    this->palabras = 0;
    this->leido = false;
}

// La extraccion con >> sobre un string salta los espacios en blanco y los
// saltos de linea, asi que cada extraccion exitosa es una palabra.
contador_palabras_t& contador_palabras_t::operator<<(const std::string& nombre_archivo) {
    std::ifstream entrada(nombre_archivo);
    if (!entrada) {
        this->leido = false;
        return *this;
    }

    std::string palabra;
    while (entrada >> palabra) {
        this->palabras++;
    }

    entrada.close();
    this->leido = true;
    return *this;
}

entero contador_palabras_t::total() const {
    return this->palabras;
}

bool contador_palabras_t::ok() const {
    return this->leido;
}

void contador_palabras_t::reiniciar() {
    this->palabras = 0;
    this->leido = false;
}
