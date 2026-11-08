#include <iostream>
#include <string>
#include <vector>
#include "COrdenar.h"
#include "COrdenarEnteros.h"
#include "COrdenarFlotantes.h"
#include "ordenar.h"
#include "tipos.h"

using namespace std;

int main() {
    vector<entero> enteros = {42, 7, 19, 3, 88, 25};
    vector<real> flotantes = {4.5f, 1.25f, 9.75f, 0.5f, 3.125f};

    cout << "--- Solucion con herencia ---" << endl;
    vector<COrdenar*> ordenadores;
    ordenadores.push_back(new COrdenarEnteros(enteros));
    ordenadores.push_back(new COrdenarFlotantes(flotantes));

    for (size_t i = 0; i < ordenadores.size(); i++) {
        ordenadores[i]->Ordenar();
        ordenadores[i]->Mostrar();
    }

    for (size_t i = 0; i < ordenadores.size(); i++) {
        delete ordenadores[i];
    }
    ordenadores.clear();

    cout << "\n--- Solucion con template ---" << endl;
    ordenar(enteros);
    mostrar(enteros);
    ordenar(flotantes);
    mostrar(flotantes);

    vector<string> palabras = {"pera", "uva", "manzana", "kiwi"};
    ordenar(palabras);
    mostrar(palabras);

    return 0;
}
