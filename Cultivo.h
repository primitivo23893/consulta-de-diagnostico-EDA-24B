#ifndef CULTIVO_H
#define CULTIVO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "AnalisisBase.h"
#include "Componente.h"
#include "ListaEnlazada.h"
using namespace std;

class Cultivo : public AnalisisBase {
    private:
        ListaEnlazada<Componente> componentes;
        string nombre;
        int folio;
        string fecha;
        string tipo;
    public:
        Cultivo();
        void setNombre(const string& _nombre);
        string getNombre() const;
        void setFolio(int _folio);
        int getFolio() const;
        void setFecha(const string& _fecha);
        string getFecha() const;
        void setTipo(const string& _tipo);
        string getTipo() const;

        void addComponente(Componente* componente);
        void removeComponente(int pos);
        void editarComponente(int pos, Componente* componente);
        
        string str() const override;
        void guardarEnArchivo(ofstream& archivo) const override;

};

#endif // CULTIVO_H
