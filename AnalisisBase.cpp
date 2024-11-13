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

string AnalisisBase::str() {
    stringstream sout;
    sout << "Nombre: " << nombre << "\nFolio: " << folio << "\nFecha: " << fecha << "\nTipo: " << tipo;
    for (const auto& componente : componentes) {
        sout << componente.str() << endl;
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

