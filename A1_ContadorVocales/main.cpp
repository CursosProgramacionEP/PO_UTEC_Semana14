#include <iostream>
#include <string>
#include "tipos.h"
#include "contador_vocales.h"

using namespace std;

int main() {
    string nombre_entrada;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre_entrada;

    entero frecuencia[TOTAL_VOCALES];
    if (!contar_vocales(nombre_entrada, frecuencia)) {
        cout << "No se pudo abrir el archivo " << nombre_entrada << endl;
        return 1;
    }

    cout << "\nVocal y frecuencia en el texto:" << endl;
    for (entero i = 0; i < TOTAL_VOCALES; i++) {
        cout << vocal_en(i) << ": " << frecuencia[i] << endl;
    }

    const string nombre_salida = "vocales.txt";
    if (!escribir_frecuencias(nombre_salida, frecuencia)) {
        cout << "No se pudo escribir " << nombre_salida << endl;
        return 1;
    }

    cout << "\nResultado grabado en " << nombre_salida << endl;
    return 0;
}
