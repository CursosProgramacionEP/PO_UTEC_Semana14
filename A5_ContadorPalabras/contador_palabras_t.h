#ifndef CONTADOR_PALABRAS_T_H
#define CONTADOR_PALABRAS_T_H

#include <string>
#include "tipos.h"

// El operador << es un metodo de la clase porque el objeto va a la izquierda:
//     contador << "origen.txt";
// Devolver una referencia al propio objeto permite encadenar varios archivos.
class contador_palabras_t {
private:
    entero palabras;
    bool leido;

public:
    contador_palabras_t();

    contador_palabras_t& operator<<(const std::string& nombre_archivo);

    entero total() const;
    bool ok() const;
    void reiniciar();
};

#endif
