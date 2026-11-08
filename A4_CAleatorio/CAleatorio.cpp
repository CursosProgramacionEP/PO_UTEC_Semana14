#include <fstream>
#include <iostream>
#include "CAleatorio.h"

CAleatorio::CAleatorio() {
    this->loaded = false;
}

// La lectura con >> dentro de la condicion del while se detiene sola:
// al llegar al final del archivo la extraccion falla y el flujo vale falso.
void CAleatorio::LoadData() {
    std::string nombre_archivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombre_archivo;

    std::ifstream entrada(nombre_archivo);
    if (!entrada) {
        std::cout << "No se pudo abrir el archivo " << nombre_archivo << std::endl;
        this->loaded = false;
        return;
    }

    this->numeros.clear();
    Entero valor = 0;
    while (entrada >> valor) {
        this->numeros.push_back(valor);
    }

    entrada.close();
    this->loaded = true;
    std::cout << "Se cargaron " << this->numeros.size() << " numeros" << std::endl;
}

// Ordenamiento por insercion: cada elemento se abre paso hacia atras
// hasta quedar en su lugar.
void CAleatorio::InsertSort() {
    for (size_t i = 1; i < this->numeros.size(); i++) {
        Entero actual = this->numeros[i];
        entero j = static_cast<entero>(i) - 1;
        while (j >= 0 && this->numeros[j] > actual) {
            this->numeros[j + 1] = this->numeros[j];
            j--;
        }
        this->numeros[j + 1] = actual;
    }
}

void CAleatorio::QuickSort() {
    if (this->numeros.empty()) {
        return;
    }
    this->QuickSort(0, static_cast<Entero>(this->numeros.size()) - 1);
}

void CAleatorio::QuickSort(Entero inicio, Entero fin) {
    if (inicio < fin) {
        Entero pivote = this->Particion(inicio, fin);
        this->QuickSort(inicio, pivote - 1);
        this->QuickSort(pivote + 1, fin);
    }
}

// Deja a la izquierda los menores que el ultimo elemento y devuelve
// la posicion final de ese pivote.
Entero CAleatorio::Particion(Entero inicio, Entero fin) {
    Entero pivote = this->numeros[fin];
    Entero menor = inicio - 1;

    for (Entero j = inicio; j < fin; j++) {
        if (this->numeros[j] <= pivote) {
            menor++;
            std::swap(this->numeros[menor], this->numeros[j]);
        }
    }

    std::swap(this->numeros[menor + 1], this->numeros[fin]);
    return menor + 1;
}

Boleano CAleatorio::Grabar(const std::string& nombre_archivo) {
    std::ofstream salida(nombre_archivo);
    if (!salida) {
        return false;
    }

    for (size_t i = 0; i < this->numeros.size(); i++) {
        salida << this->numeros[i] << std::endl;
    }

    salida.close();
    return true;
}

void CAleatorio::Sort() {
    if (!this->loaded) {
        std::cout << "Primero cargue los datos" << std::endl;
        return;
    }

    entero opcion = 0;
    std::cout << "Ordenar con 1) InsertSort  2) QuickSort: ";
    std::cin >> opcion;

    if (opcion == 1) {
        this->InsertSort();
    } else {
        this->QuickSort();
    }

    const std::string nombre_salida = "ordenados.txt";
    if (this->Grabar(nombre_salida)) {
        std::cout << "Lista ordenada grabada en " << nombre_salida << std::endl;
    } else {
        std::cout << "No se pudo escribir " << nombre_salida << std::endl;
    }
}

void CAleatorio::Show() {
    for (size_t i = 0; i < this->numeros.size(); i++) {
        std::cout << this->numeros[i] << " ";
    }
    std::cout << std::endl;
}

// La busqueda binaria descarta la mitad del vector en cada paso,
// por eso solo sirve sobre un vector ya ordenado.
Entero CAleatorio::BinarySearch() {
    if (!this->loaded) {
        std::cout << "Primero cargue los datos" << std::endl;
        return -1;
    }

    Entero valor = 0;
    std::cout << "Ingrese numero a buscar: ";
    std::cin >> valor;

    entero inicio = 0;
    entero fin = static_cast<entero>(this->numeros.size()) - 1;

    while (inicio <= fin) {
        entero medio = inicio + (fin - inicio) / 2;
        if (this->numeros[medio] == valor) {
            return medio;
        }
        if (this->numeros[medio] < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}
