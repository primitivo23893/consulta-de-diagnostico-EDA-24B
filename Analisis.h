#ifndef ANALISIS_H
#define ANALISIS_H

#include <iostream>
#include <string>

#include "ListaEnlazada.h"
using namespace std;

class Analisis {

private:
    ListaEnlazada<AnalisisBase>* listaAnalisis;
public:

    Analisis();
    ~Analisis();

    void addEGO(EGO* ego);
    void removeEGO(int pos);
    void addQS(QS* qs);
    void removeQS(int pos);
    void addCultivo(Cultivo* cultivo);
    void removeCultivo(int pos);

    void ordenarTipo();
    void ordenarFecha();
    void ordenarFolio();
    void ordenarAlfabeto();

    void guardarEnArchivo() const;
    void recuperarDeArchivo();

    void mostrarTodo() const;

    string str() const;
};

#endif // ANALISIS_H