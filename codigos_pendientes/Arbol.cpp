#include "Arbol.h"
#include <iostream>
#include <string>
using namespace std;

Arbol::Arbol() : raiz(nullptr) {}

Arbol::~Arbol() {
    destruir(raiz);  // Para destruir todos los nodos al destruir el árbol
}

void Arbol::destruir(Nodo* nodo) {
    if (nodo != nullptr) {
        destruir(nodo->izquierda);   // Llamamos recursivamente al subárbol izquierdo
        destruir(nodo->derecha);     // Llamamos recursivamente al subárbol derecho
        delete nodo;                 // Liberamos la memoria del nodo
    }
}

void Arbol::insertar(AnalisisBase* analisis) {
    insertar(raiz, analisis);
}

void Arbol::insertar(Nodo*& nodo, AnalisisBase* analisis) {
    if (nodo == nullptr) {
        nodo = new Nodo(analisis);  // Crear un nuevo nodo si el espacio está vacío
    } else {
        // Comparar por nombre (o el criterio que prefieras)
        if (analisis->getNombre() < nodo->analisis->getNombre()) {
            insertar(nodo->izquierda, analisis);  // Insertamos en el subárbol izquierdo
        } else {
            insertar(nodo->derecha, analisis);    // Insertamos en el subárbol derecho
        }
    }
}

void Arbol::imprimirInOrden() const {
    imprimirInOrden(raiz);  // Llamamos a la función recursiva para imprimir en orden
}

void Arbol::imprimirInOrden(Nodo* nodo) const {
    if (nodo != nullptr) {
        imprimirInOrden(nodo->izquierda);  // Recursivamente imprimir el subárbol izquierdo
        cout << nodo->analisis->str() << endl;  // Imprimimos el análisis 
        imprimirInOrden(nodo->derecha);  // Recursivamente imprimir el subárbol derecho
    }
}
