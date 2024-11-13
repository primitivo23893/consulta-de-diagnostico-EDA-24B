// ListaEnlazada.h
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "AnalisisBase.h"

template <class T>
class Nodo {
public:
    T* dato;
    Nodo<T>* siguiente;
    
    Nodo(T* val) : dato(val), siguiente(nullptr) {}
};

template <class T>
class ListaEnlazada {
private:
    Nodo<T>* inicio;
    int tamano;

public:
    ListaEnlazada();
    ~ListaEnlazada();
    void agregarInicio(T* valor);
    void agregarFinal(T* valor);
    bool eliminarInicio();
    bool eliminarFinal();
    bool eliminarPosicion(int pos);
    void mostrar() const;
    bool estaVacia() const;
    int getTamano() const;
    Nodo<T>* obtenerEnPosicion(int pos) const;
    Nodo<T>* getInicio() const;
    void guardarEnArchivo() const;
};

#endif // LISTAENLAZADA_H
