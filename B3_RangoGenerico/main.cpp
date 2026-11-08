#include <iostream>
#include "rango.h"
#include "tipos.h"

using namespace std;

int main() {
    rango<entero> r1(1, 20, 2);
    cout << "--- rango<entero>(1, 20, 2) ---" << endl;
    while (!r1.stop()) {
        cout << r1++ << " ";
    }
    cout << endl;

    rango<caracter> r2('A', 'J');
    cout << "\n--- rango<caracter>('A', 'J') ---" << endl;
    while (!r2.stop()) {
        cout << r2++ << " ";
    }
    cout << endl;

    rango<entero> r3(0, 5);
    cout << "\n--- rango<entero>(0, 5) ---" << endl;
    while (!r3.stop()) {
        cout << r3++ << " ";
    }
    cout << endl;

    return 0;
}
