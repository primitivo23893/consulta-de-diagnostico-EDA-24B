#ifndef ARBOL_H
#define ARBOL_H

#include "AnalisisBase.h"

// Definimos la estructura del nodo del árbol
struct Nodo {
    AnalisisBase* analisis;   // Puntero al objeto AnalisisBase
    Nodo* izquierda;          // Puntero al subárbol izquierdo
    Nodo* derecha;            // Puntero al subárbol derecho

    // Constructor de Nodo
    Nodo(AnalisisBase* a) : analisis(a), izquierda(nullptr), derecha(nullptr) {}
};

class Arbol {
private:
    Nodo* raiz;   // Puntero a la raíz del árbol

    void insertar(Nodo*& nodo, AnalisisBase* analisis);
    void imprimirInOrden(Nodo* nodo) const;
    void destruir(Nodo* nodo);

public:
    Arbol();
    ~Arbol();

    void insertar(AnalisisBase* analisis);
    void imprimirInOrden() const;   // Para imprimir los elementos en orden
    void destruir();                // Para eliminar todos los nodos del árbol
};

#endif 