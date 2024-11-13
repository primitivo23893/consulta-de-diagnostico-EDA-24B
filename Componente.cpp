#include <iostream>
#include <string>
#include "Componente.h"

using namespace std;

void Componente::setNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

void Componente::setValor(const string& nuevoValor) {
    valor = nuevoValor;
}

void Componente::setRango(const string& nuevoRango) {
    rango = nuevoRango;
}

string Componente::getNombre() const {
    return nombre;
}

string Componente::getValor() const {
    return valor;
}

string Componente::getRango() const {
    return rango;
}

int main(){
    Componente comp;
    string tempNombre, tempValor, tempRango;

    cout << "Ingrese el nombre del componente: ";
    getline(cin, tempNombre);
    cout << "Ingrese el valor del componente: ";
    getline(cin, tempValor);
    cout << "Ingrese el rango del componente: ";
    getline(cin, tempRango);

    comp.setNombre(tempNombre);
    comp.setValor(tempValor);
    comp.setRango(tempRango);

    cout << endl <<"Datos del componente: " << endl;
    cout << "Nombre: " << comp.getNombre() << endl;
    cout << "Valor: " << comp.getValor() << endl;
    cout << "Rango: " << comp.getRango() << endl;

    return 0;
}
