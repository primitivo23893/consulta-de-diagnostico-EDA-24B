#ifndef EGO_H
#define EGO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class EGO {
    private:
        //lista
        string nombre;
        int folio;
        string fecha;
        string tipo;
    public:
        EGO();
        void setNombre(const string& _nombre);
        string getNombre() const;
        void setFolio(int _folio);
        int getFolio() const;
        void setFecha(const string& _fecha);
        string getFecha() const;
        void setTipo(const string& _tipo);
        string getTipo() const;
        
        string str();
        void guardarEnArchivo(ofstream& archivo) const;

};

#endif // EGO_H
