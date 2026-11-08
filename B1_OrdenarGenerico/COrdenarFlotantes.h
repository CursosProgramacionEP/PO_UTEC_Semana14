#ifndef CORDENARFLOTANTES_H
#define CORDENARFLOTANTES_H

#include <vector>
#include "COrdenar.h"
#include "tipos.h"

class COrdenarFlotantes : public COrdenar {
private:
    std::vector<real> datos;

public:
    COrdenarFlotantes(const std::vector<real>& datos);

    void Ordenar() override;
    void Mostrar() const override;
};

#endif
