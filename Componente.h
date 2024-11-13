#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <sstream>
#include <iomanip>

#include <string>
using namespace std;

class Componente {
private:
    string nombre;
    string valor;
    string rango;

public:
    void setNombre(const string& nuevoNombre);
    void setValor(const string& nuevoValor);
    void setRango(const string& nuevoRango);

    string getNombre() const;
    string getValor() const;
    string getRango() const;

    string str() const;
};

#endif
