#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "registro.h"

// El nombre puede tener espacios, por eso se lee con getline y no con >>.
// El ignore() descarta el salto de linea que dejo pendiente la lectura anterior.
std::vector<Persona> leer_personas(entero n) {
    std::vector<Persona> personas;

    for (entero i = 0; i < n; i++) {
        std::string dni;
        std::string nombre;
        entero edad = 0;
        real salario = 0.0f;

        std::cout << "\nPersona " << i + 1 << std::endl;
        std::cout << "DNI    : ";
        std::cin >> dni;
        std::cin.ignore();
        std::cout << "Nombre : ";
        std::getline(std::cin, nombre);
        std::cout << "Edad   : ";
        std::cin >> edad;
        std::cout << "Salario: ";
        std::cin >> salario;

        personas.push_back(Persona(dni, nombre, edad, salario));
    }

    return personas;
}

// ctime devuelve la fecha con un salto de linea al final que aqui no sirve.
std::string fecha_y_hora_actual() {
    std::time_t ahora = std::time(nullptr);
    std::string texto = std::ctime(&ahora);
    if (!texto.empty() && texto.back() == '\n') {
        texto.pop_back();
    }
    return texto;
}

bool grabar_registro(const std::string& nombre_archivo, const std::vector<Persona>& personas) {
    std::ofstream salida(nombre_archivo);
    if (!salida) {
        return false;
    }

    const std::string linea(50, '-');

    salida << linea << std::endl;
    salida << "Registro del " << fecha_y_hora_actual() << std::endl;
    salida << linea << std::endl;

    salida << std::left << std::setw(12) << "DNI"
           << std::setw(22) << "Nombre"
           << std::right << std::setw(6) << "edad"
           << std::setw(10) << "salario" << std::endl;

    salida << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < personas.size(); i++) {
        salida << std::left << std::setw(12) << personas[i].getDni()
               << std::setw(22) << personas[i].getNombre()
               << std::right << std::setw(6) << personas[i].getEdad()
               << std::setw(10) << personas[i].getSalario() << std::endl;
    }

    salida.close();
    return true;
}
