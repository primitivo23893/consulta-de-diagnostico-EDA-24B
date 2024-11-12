#ifndef ANALISIS_H
#define ANALISIS_H

#include <iostream>
#include <string>

using namespace std;

class Analisis {

private:

public:

    Analisis();

    void addEGO();
    void removeEGO();
    void addQS();
    void removeQS();
    void addCultivo();
    void removeCultivo();

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