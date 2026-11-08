#include <iostream>
#include <string>
#include <vector>
#include "Persona.h"
#include "registro.h"
#include "tipos.h"

using namespace std;

int main() {
    entero n = 0;
    string nombre_archivo;

    cout << "Cantidad de personas: ";
    cin >> n;
    cout << "Nombre del archivo  : ";
    cin >> nombre_archivo;

    vector<Persona> personas = leer_personas(n);

    if (!grabar_registro(nombre_archivo, personas)) {
        cout << "\nNo se pudo escribir " << nombre_archivo << endl;
        return 1;
    }

    cout << "\nSe grabaron " << personas.size() << " personas en " << nombre_archivo << endl;
    return 0;
}
