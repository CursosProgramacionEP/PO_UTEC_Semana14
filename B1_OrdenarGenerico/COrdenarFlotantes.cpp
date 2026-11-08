#include <iostream>
#include "COrdenarFlotantes.h"

COrdenarFlotantes::COrdenarFlotantes(const std::vector<real>& datos) {
    this->datos = datos;
}

void COrdenarFlotantes::Ordenar() {
    for (size_t i = 1; i < this->datos.size(); i++) {
        real actual = this->datos[i];
        entero j = static_cast<entero>(i) - 1;
        while (j >= 0 && this->datos[j] > actual) {
            this->datos[j + 1] = this->datos[j];
            j--;
        }
        this->datos[j + 1] = actual;
    }
}

void COrdenarFlotantes::Mostrar() const {
    for (size_t i = 0; i < this->datos.size(); i++) {
        std::cout << this->datos[i] << " ";
    }
    std::cout << std::endl;
}
