#include <iostream>
#include "CAleatorio.h"
#include "tipos.h"

using namespace std;

int main() {
    CAleatorio *ptr = new CAleatorio();

    ptr->LoadData();
    ptr->Sort();
    ptr->Show();

    Entero posicion = ptr->BinarySearch();
    if (posicion != -1) {
        cout << "Encontrado en la posicion " << posicion << endl;
    } else {
        cout << "No se encontro en la lista" << endl;
    }

    delete ptr;
    return 0;
}
