// Lista simple

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <sstream>
using namespace std;
template <typename T>
class Nodo {
    public:
    T valor;
    Nodo<T>* sig;
    // Nodo(T val) : valor(val), sig(nullptr) {}
    Nodo(const T& val) : valor(val), sig(nullptr) {}
    Nodo() : sig(nullptr) {}
    Nodo& operator=(Nodo& nodo) {
        if (this != &nodo) {
            valor = nodo.valor;
            sig = nodo.sig ? new Nodo(*nodo.sig) : nullptr; // Copia profunda
        }
        return *this;
    }
};
template <typename T>
class Lista {
    Nodo<T>* cabeza;
    public:
    Lista() : cabeza(nullptr) {}
    Lista(const T* valor) : cabeza(nullptr) {
        push_back(valor);
    }
    Lista(T&& valor) : cabeza(nullptr) {
        push_back(valor);
    }
    Lista(const T& valor) : cabeza(nullptr) {
        push_back(valor);
    }
    Lista(const Lista<T>& lista) : cabeza(nullptr) {
        Nodo<T>* actual = lista.cabeza;
        while (actual) {
            push_back(actual->valor); // Crear nuevos nodos copiando el valor
            actual = actual->sig;
        }
    }
    ~Lista() {
        Nodo<T>* aux;
        while (cabeza != nullptr) {
            aux = cabeza;
            cabeza = cabeza->sig;
            delete aux;
        }
    }
    // Agregar al final
    void push_back(T* valor) {
        Nodo<T>* nuevoNodo;
        Nodo<T>* actual;
        nuevoNodo = new Nodo<T>(*valor);
        if (this->cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* actual = ultimoNodo();
            actual->sig = nuevoNodo;
        }
        nuevoNodo = nullptr;
        delete nuevoNodo;
    }
    void push_back(const T&& valor) {
        Nodo<T>* nuevoNodo;
        // verifica si el ptr no esta vacio
        nuevoNodo = new Nodo<T>(move(valor));
        if (this->cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* actual = ultimoNodo();
            actual->sig = nuevoNodo;
        }
        nuevoNodo = nullptr;
        delete nuevoNodo;
    }
    void push_back(const T& valor) {
        Nodo<T>* nuevoNodo;
        Nodo<T>* actual;
        nuevoNodo = new Nodo<T>(valor);
        if (this->cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* actual = ultimoNodo();
            actual->sig = nuevoNodo;
        }
        nuevoNodo = nullptr;
        delete nuevoNodo;
    }
    void push_back(const Lista<T>& lista) {
        Nodo<T>* actual = lista.cabeza;
        while (actual) {
            push_back(actual->valor); // Agregar cada elemento de la lista pasada
            actual = actual->sig;
        }
    }
    // agragar al principio
    void push_front(T* valor) {
        Nodo<T>* nuevoNodo;
        nuevoNodo = new Nodo<T>(*valor);
        if (this->cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            nuevoNodo->sig = cabeza;
            cabeza = nuevoNodo;
        }
        nuevoNodo = nullptr;
        delete nuevoNodo;
    }
    void push_front(const T&& valor) {
        Nodo<T>* nuevoNodo;
        // verifica si el ptr no esta vacio
        nuevoNodo = new Nodo<T>(move(valor));
        if (this->cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            nuevoNodo->sig = cabeza;
            cabeza = nuevoNodo;
        }
        nuevoNodo = nullptr;
        delete nuevoNodo;
    }
    void push_front(const T& valor) {
        Nodo<T>* nuevoNodo;
        nuevoNodo = new Nodo<T>(valor);
        if (this->cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            nuevoNodo->sig = cabeza;
            cabeza = nuevoNodo;
        }
        nuevoNodo = nullptr;
        delete nuevoNodo;
    }
    void push_front(const Lista<T>& lista) {
        Nodo<T>* actual = lista.cabeza;
        while (actual) {
            push_back(actual->valor); // Agregar cada elemento de la lista pasada
            actual = actual->sig;
        }
    }
    T& getValue(int index) {
        return buscaNodo(index)->valor;
    }
    T& getValue(int index) const {
        return buscaNodo(index)->valor;
    }
    void imprimir() const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->valor << " -> ";
            actual = actual->sig;
        }
        cout << "nullptr" << endl;
    }
    bool pop_front() {
        bool eliminado;
        Nodo<T>* actual = cabeza;
        if (cabeza == nullptr) {
            eliminado = false;
        } else {
            cabeza = cabeza->sig;
            delete actual;
            eliminado = true;
        }
        return eliminado;
    }
    bool pop(int index) {
        bool eliminado;
        Nodo<T>* actual = cabeza;
        Nodo<T>* auxiliar;
        Nodo<T>* nodoBuscado;
        if (validaRango(index)) {
            if (index == 0) {
                return pop_front();
            } else {
                nodoBuscado = buscaNodo(index);
                while (actual->sig != nodoBuscado) {
                    actual = actual->sig;
                }
                auxiliar = actual->sig;
                actual->sig = actual->sig->sig;
                delete auxiliar;
                eliminado = true;
            }
        } else {
            eliminado = false;
        }
        return eliminado;
    }
    bool pop_back() {
        bool eliminado;
        if (cabeza == nullptr) {
            eliminado = false;
        } else if (cabeza->sig == nullptr) {
            cabeza = nullptr;
            eliminado = true;
        } else {
            Nodo<T>* actual = cabeza;
            Nodo<T>* aux;
            while (actual->sig->sig != nullptr) {
                actual = actual->sig;
            }
            aux = actual->sig;
            actual->sig = nullptr;
            delete aux;
            eliminado = true;
        }
        return eliminado;
    }
    int size() {
        int tam;
        Nodo<T>* actual;
        if (cabeza != nullptr) {
            tam = 1;
            actual = cabeza;
            while (actual->sig != nullptr) {
                actual = actual->sig;
                tam++;
            }
        } else
            tam = 0;
        return tam;
    }
    int size() const {
        int tam;
        Nodo<T>* actual;
        if (cabeza != nullptr) {
            tam = 1;
            actual = cabeza;
            while (actual->sig != nullptr) {
                actual = actual->sig;
                tam++;
            }
        } else
            tam = 0;
        return tam;
    }
    T& operator[](int index) {
        return getValue(index);
    }
    const T& operator[](int index) const {
        return getValue(index);
    }

    void set(int index, const T& valor) {
        if (validaRango(index)) {
            Nodo<T>* nodo = buscaNodo(index);
            nodo->valor = valor;
        } else {
            throw out_of_range("Índice fuera de rango");
        }
    }
    friend ostream& operator<<(ostream& os, const Lista lista) {
        Nodo<T>* actual = lista.cabeza;
        while (actual != nullptr) {
            os << actual->valor << " -> ";
            actual = actual->sig;
        }
        os << "nullptr" << endl;
        return os;
    }
    private:
    Nodo<T>* ultimoNodo() {
        Nodo<T>* actual = cabeza;
        while (actual->sig != nullptr) {
            actual = actual->sig;
        }
        return actual;
    }
    bool cabezaNula() {
        return (cabeza == nullptr) ? false : true;
    }
    Nodo<T>* buscaNodo(int index) {
        Nodo<T>* actual;
        int i;
        if (validaRango(index)) {
            actual = cabeza;
            i = 0;
            while (actual->sig != nullptr && i <= index) {
                if (i == index)
                    break;
                actual = actual->sig;
                i++;
            }
        } else
            actual = cabeza;
        return actual;
    }
    Nodo<T>* buscaNodo(int index) const {
        Nodo<T>* actual;
        int i;
        if (validaRango(index)) {
            actual = cabeza;
            i = 0;
            while (actual->sig != nullptr && i <= index) {
                if (i == index)
                    break;
                actual = actual->sig;
                i++;
            }
        } else
            actual = cabeza;
        return actual;
    }
    bool validaRango(int index) {
        return (0 <= index && index < size()) ? true : false;
    }
    bool validaRango(int index) const {
        return (0 <= index && index < size()) ? true : false;
    }
};
#endif