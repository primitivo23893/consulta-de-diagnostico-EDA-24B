#ifndef ANALISISBASE_H
#define ANALISISBASE_H

#include <bits/stdc++.h>
#include <iomanip>
#include "Componente.h"


using namespace std;

class AnalisisBase {
private:
    vector<Componente> componentes;
    string nombre;
    int folio;
    string fecha;

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
    virtual string getTipo() const;

    void addComponente(Componente* componente);
    void removeComponente(int pos);
    void editarComponente(int pos, Componente* componente);
    int buscarComponentePorNombre( string& _nombre);
    string mostrarComponente(int pos) ;

    void addAnalisis(AnalisisBase* analisis);
    int getTamanoAnalisis(AnalisisBase* analisis) const;
    int buscarPorFolio(int folio) const;
    string mostrarPorFolio(int folio) const;
    void removeAnalisis(int pos);
    void editarAnalisis(int pos, AnalisisBase* analisis);
    AnalisisBase* getAnalisis(int pos) const;
    // string str() const override;
    // void guardarEnArchivo(ofstream& archivo) const override;
    vector<Componente> getComponentes() const;

    string ordenarNombre()const;
    string ordenarFecha()const;
    string ordenarTipo()const;
};

#endif // ANALISISBASE_H