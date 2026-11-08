#include <iostream>
#include <string>
#include <vector>
#include "lista_numeros.h"
#include "tipos.h"

using namespace std;

int main() {
    string nombre_archivo;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre_archivo;

    vector<entero> numeros;
    if (!leer_lista(nombre_archivo, numeros)) {
        cout << "No se pudo abrir el archivo " << nombre_archivo << endl;
        return 1;
    }

    ordenar(numeros);
    mostrar(numeros);

    entero valor = 0;
    cout << "Ingrese numero a buscar: ";
    cin >> valor;

    if (buscar(numeros, valor) != -1) {
        cout << valor << " pertenece a la lista" << endl;
    } else {
        cout << valor << " no pertenece a la lista" << endl;
    }

    return 0;
}
