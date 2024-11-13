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
    int buscarComponentePorNombre( string& _nombre);
    string mostrarComponente(int pos) ;

    void addAnalisis(AnalisisBase* analisis);
    string mostrarTodo() const;
    int getTamanoAnalisis(AnalisisBase* analisis) const;
    int buscarPorFolio(int folio) const;
    string mostrarPorFolio(int folio) const;
    void removeAnalisis(int pos);
    // string str() const override;
    // void guardarEnArchivo(ofstream& archivo) const override;
};

#endif // ANALISISBASE_H