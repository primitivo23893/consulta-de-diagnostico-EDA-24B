//ListaEnlazada.cpp
#include "ListaEnlazada.h"

template <class T>
ListaEnlazada<T>::ListaEnlazada() : inicio(nullptr), tamano(0) {}

template <class T>
ListaEnlazada<T>::~ListaEnlazada() {
    while(inicio != nullptr) {
        Nodo<T>* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
    }
}

template <class T>
void ListaEnlazada<T>::agregarInicio(T* valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    nuevo->siguiente = inicio;
    inicio = nuevo;
    tamano++;
}

template <class T>
void ListaEnlazada<T>::agregarFinal(T* valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    
    if (inicio == nullptr) {
        inicio = nuevo;
    } else {
        Nodo<T>* temp = inicio;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    tamano++;
}

template <class T>
bool ListaEnlazada<T>::eliminarInicio() {
    if (inicio == nullptr) return false;
    
    Nodo<T>* temp = inicio;
    inicio = inicio->siguiente;
    delete temp;
    tamano--;
    return true;
}

template <class T>
bool ListaEnlazada<T>::eliminarFinal() {
    if (inicio == nullptr) return false;
    
    if (inicio->siguiente == nullptr) {
        delete inicio;
        inicio = nullptr;
        tamano--;
        return true;
    }
    
    Nodo<T>* temp = inicio;
    while (temp->siguiente->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    
    delete temp->siguiente;
    temp->siguiente = nullptr;
    tamano--;
    return true;
}

template <class T>
bool ListaEnlazada<T>::eliminarPosicion(int pos) {
    if (pos < 0 || pos >= tamano || inicio == nullptr) return false;
    
    if (pos == 0) return eliminarInicio();
    
    Nodo<T>* temp = inicio;
    for (int i = 0; i < pos-1; i++) {
        temp = temp->siguiente;
    }
    
    Nodo<T>* eliminar = temp->siguiente;
    temp->siguiente = eliminar->siguiente;
    delete eliminar;
    tamano--;
    return true;
}

template <class T>
void ListaEnlazada<T>::mostrar() const {
    Nodo<T>* temp = inicio;
    while (temp != nullptr) {
        cout << "Nombre: " << temp->dato->getNombre() 
            << ", Descripcion: " << temp->dato->getDescripcion() << endl;
        temp = temp->siguiente;
    }
}

template <class T>
bool ListaEnlazada<T>::estaVacia() const {
    return inicio == nullptr;
}

template <class T>
int ListaEnlazada<T>::getTamano() const {
    return tamano;
}
template <typename T>
void ListaEnlazada<T>::guardarEnArchivo() const {
    ofstream archivo("analisi_clinicos.txt", ios::app);
    if (archivo.is_open()) {
        Nodo<T>* temp = cabeza;
        while (temp) {
            temp->dato.guardarEnArchivo(archivo);
            temp = temp->siguiente;
        }
        archivo.close();
        cout << "Guardado exitosamente en el archivo.\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
}


