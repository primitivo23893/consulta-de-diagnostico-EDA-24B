#include <iostream>
#include <string>
#include "Componente.h"

using namespace std;

Componente::Componente(string nombre, string valor, string rango)
    :nombre(nombre), valor(valor), rango(rango) {}

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
string Componente::str() const {
    stringstream sout;
    sout << "Nombre: " << nombre << "\nValor: " << valor << "\nRango: " << rango;
    return sout.str();
}