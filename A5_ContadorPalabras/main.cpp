#include <iostream>
#include <string>
#include "contador_palabras_t.h"
#include "tipos.h"

using namespace std;

int main() {
    string nombre_archivo;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre_archivo;

    contador_palabras_t contador;
    contador << nombre_archivo;

    if (!contador.ok()) {
        cout << "No se pudo abrir el archivo " << nombre_archivo << endl;
        return 1;
    }

    cout << "El archivo tiene " << contador.total() << " palabras" << endl;
    return 0;
}
