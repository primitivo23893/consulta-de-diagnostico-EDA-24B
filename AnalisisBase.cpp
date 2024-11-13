#include "AnalisisBase.h"

vector<AnalisisBase*> AnalisisBase::analisis;

AnalisisBase::AnalisisBase()
    : nombre(""), folio(0), fecha(""), tipo("") {}


void AnalisisBase::setNombre(const string& _nombre) {
    nombre = _nombre;
}

string AnalisisBase::getNombre() const {
    return nombre;
}

void AnalisisBase::setFolio(int _folio) {
    folio = _folio;
}

int AnalisisBase::getFolio() const {
    return folio;
}

void AnalisisBase::setFecha(const string& _fecha) {
    fecha = _fecha;
}

string AnalisisBase::getFecha() const {
    return fecha;
}

void AnalisisBase::setTipo(const string& _tipo) {
    tipo = _tipo;
}

string AnalisisBase::getTipo() const {
    return tipo;
}

void AnalisisBase::addComponente(Componente* componente) {
    componentes.push_back(*componente);
}

void AnalisisBase::removeComponente(int pos) {
    componentes.erase(componentes.begin() + pos);
}

void AnalisisBase::editarComponente(int pos, Componente* componente) {
    if (pos < 0 || pos >= componentes.size()) {
        cout << "Posición inválida" << endl;
        return;
    }

    componentes[pos] = *componente;
}
int AnalisisBase::buscarComponentePorNombre(string& _nombre) {
    int pos = 0;
    cout<< "Componentes.size() es: " << componentes.size() << endl;
    for(const auto& componente : componentes){
        cout << componente.getNombre() << endl;
        if(componente.getNombre() == _nombre){
            return pos;
        }
        pos++;
    }
    // for (int i = 0; i < componentes.size(); i++) {
    //         cout << componentes[i].str() << endl;
    //     if (componentes[i].getNombre() == nombre) {
    //         return i;
    //     }
    // }
    return -1;
}
string AnalisisBase::mostrarComponente(int pos) {
    if (pos < 0 || pos >= componentes.size()) {
        return "Posición inválida";
    }
    return componentes[pos].str();
}

string AnalisisBase::str() {
    stringstream sout;
    sout << "\nNombre: " << nombre << "\tFolio: " << folio << "\tFecha: " << fecha << "\tTipo: " << tipo;
    sout << "\nComponentes: ";
    sout << "\nNombre\tValor\t\tRango\n";
    for (const auto& componente : componentes) {
        sout <<componente.str() << endl;
    }
    return sout.str();
}
string AnalisisBase::mostrarTodo()const{
    stringstream sout;
    for(const auto& analisis : AnalisisBase::analisis){
        sout << analisis->str() << endl;
    }
    return sout.str();
}
void AnalisisBase::addAnalisis(AnalisisBase* analisis) {
    AnalisisBase::analisis.push_back(analisis);
}
int AnalisisBase::getTamanoAnalisis(AnalisisBase* analisis) const {
    return AnalisisBase::analisis.size();
}
int AnalisisBase::buscarPorFolio(int folio) const {
    for (int i = 0; i < AnalisisBase::analisis.size(); i++) {
        if (AnalisisBase::analisis[i]->getFolio() == folio) {
            return i;
        }
    }
    return -1;
}
string AnalisisBase::mostrarPorFolio(int folio) const {
    int pos = buscarPorFolio(folio);
    if (pos == -1) {
        return "No se encontró el análisis con el folio proporcionado.";
    }
    return AnalisisBase::analisis[pos]->str();
}
void AnalisisBase::removeAnalisis(int pos) {
    AnalisisBase::analisis.erase(AnalisisBase::analisis.begin() + pos);
}
// void AnalisisBase::guardarEnArchivo(ofstream& archivo) const {
//     if (archivo.is_open()) {
//         archivo << "Nombre del Paciente: " << nombre << endl;
//         archivo << "Tipo de Examen: " << tipo << endl;
//         // for (const auto& dato : ) {
//         //     archivo << dato.first << ": " << dato.second << endl;
//         // }
//         archivo << "--------------------------" << endl << endl;
//     } else {
//         cout << "No se pudo abrir el archivo." << endl;
//     }
// }

