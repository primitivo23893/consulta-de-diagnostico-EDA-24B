// ListaEnlazada.cpp
#ifndef LISTAENLAZADA_CPP
#define LISTAENLAZADA_CPP

#include "ListaEnlazada.h"

template <typename T>
ListaEnlazada<T>::ListaEnlazada() : cabeza(nullptr) {}

template <typename T>
void ListaEnlazada<T>::agregar(const T& nuevoDato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(nuevoDato);
    if (!cabeza) {
        cabeza = nuevoNodo;
    } else {
        Nodo<T>* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

template <typename T>
void ListaEnlazada<T>::mostrar() const {
    Nodo<T>* temp = cabeza;
    while (temp) {
        temp->dato.mostrarDatos();
        temp = temp->siguiente;
    }
}

template <typename T>
void ListaEnlazada<T>::guardarEnArchivo() const {
    ofstream archivo("cultivos_clinicos.txt", ios::app);
    if (archivo.is_open()) {
        Nodo<T>* temp = cabeza;
        while (temp) {
            temp->dato.guardarEnArchivo(archivo);
            temp = temp->siguiente;
        }
        archivo.close();
        cout << "Todos los cultivos se han guardado exitosamente en el archivo.\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar los cultivos.\n";
    }
}

#endif // LISTAENLAZADA_CPP
