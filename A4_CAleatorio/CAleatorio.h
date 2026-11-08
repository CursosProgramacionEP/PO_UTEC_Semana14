#ifndef CALEATORIO_H
#define CALEATORIO_H

#include <string>
#include <vector>
#include "tipos.h"

// Los numeros leidos del archivo viven en el vector de la clase.
// "loaded" evita ordenar o buscar sobre un vector que todavia esta vacio.
class CAleatorio {
private:
    std::vector<Entero> numeros;
    Boleano loaded;

    void InsertSort();
    void QuickSort();
    void QuickSort(Entero inicio, Entero fin);
    Entero Particion(Entero inicio, Entero fin);
    Boleano Grabar(const std::string& nombre_archivo);

public:
    CAleatorio();

    void LoadData();
    void Sort();
    void Show();
    Entero BinarySearch();
};

#endif
