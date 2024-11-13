#ifndef EGO_H
#define EGO_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class EGO {
public:
    string nombrePaciente;
    string tipoExamen;
    map<string, string> datos;

    void ingresarDatos();
    void mostrarDatos() const;
    void guardarEnArchivo(ofstream& archivo) const;
};

#endif // EGO_H
