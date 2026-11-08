#ifndef CORDENAR_H
#define CORDENAR_H

// Clase abstracta: cada hija guarda su propio vector y ordena su propio tipo.
class COrdenar {
public:
    COrdenar();
    virtual ~COrdenar();

    virtual void Ordenar() = 0;
    virtual void Mostrar() const = 0;
};

#endif
