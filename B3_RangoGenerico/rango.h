#ifndef RANGO_H
#define RANGO_H

#include "tipos.h"

// Clase generica con el mismo comportamiento que un rango de Python:
// el valor inicial entra en el recorrido y el valor final queda fuera.
// Toda la plantilla va en el .h porque el compilador necesita el cuerpo
// para generar la version de cada tipo.
template <typename T>
class rango {
private:
    T actual;
    T limite;
    entero paso;

public:
    rango(T inicio, T limite, entero paso = 1) {
        this->actual = inicio;
        this->limite = limite;
        this->paso = paso;
    }

    bool stop() const {
        return this->actual >= this->limite;
    }

    T inicio() const {
        return this->actual;
    }

    // Post-incremento: devuelve el valor actual y recien despues avanza.
    T operator++(int) {
        T copia = this->actual;
        this->actual = static_cast<T>(this->actual + this->paso);
        return copia;
    }
};

#endif
