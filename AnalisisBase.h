#ifndef ANALISISBASE_H
#define ANALISISBASE_H

#include <bits/stdc++.h>

#include "Componente.h"


using namespace std;

class AnalisisBase {
private:
    vector<Componente> componentes;
    string nombre;
    int folio;
    string fecha;
    string tipo;

    static vector<AnalisisBase*> analisis;

public:
    AnalisisBase();
    virtual ~AnalisisBase() {}
    string str();
    void guardarEnArchivo(ofstream& archivo);

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

    void addAnalisis(AnalisisBase* analisis);
    string mostrarTodo() const;
    // string str() const override;
    // void guardarEnArchivo(ofstream& archivo) const override;
};

#endif // ANALISISBASE_H