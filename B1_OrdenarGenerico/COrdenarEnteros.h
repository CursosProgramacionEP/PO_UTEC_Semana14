#ifndef CORDENARENTEROS_H
#define CORDENARENTEROS_H

#include <vector>
#include "COrdenar.h"
#include "tipos.h"

class COrdenarEnteros : public COrdenar {
private:
    std::vector<entero> datos;

public:
    COrdenarEnteros(const std::vector<entero>& datos);

    void Ordenar() override;
    void Mostrar() const override;
};

#endif
