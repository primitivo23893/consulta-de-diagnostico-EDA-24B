#ifndef CULTIVO_H
#define CULTIVO_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class Cultivo {
public:
    string nombrePaciente;
    string tipoCultivo;
    map<string, string> datos;

    void ingresarDatos();
    void mostrarDatos() const;
    void guardarEnArchivo(ofstream& archivo) const;
};

#endif // CULTIVO_H
