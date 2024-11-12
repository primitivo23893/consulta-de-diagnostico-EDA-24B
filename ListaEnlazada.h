// ListaEnlazada.h
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada();
    void agregar(const T& nuevoDato);
    void mostrar() const;
    void guardarEnArchivo() const;
};

#include "ListaEnlazada.cpp"  // Incluir la implementación

#endif // LISTAENLAZADA_H
