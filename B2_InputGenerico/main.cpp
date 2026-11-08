#include <iostream>
#include <string>
#include "input.h"
#include "tipos.h"

using namespace std;

int main() {
    auto numero = input<entero>("Ingrese dato");
    cout << numero << endl;

    auto medida = input<real>("Ingrese un numero real");
    cout << medida << endl;

    auto nombre = input<string>("Ingrese su nombre completo");
    cout << nombre << endl;

    return 0;
}
