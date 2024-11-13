#include "EGO.h"

EGO::EGO() {
    nombre = "";
    fecha = "";
    tipo = "";
    folio = 0;
}
void EGO::setNombre(const string& _nombre) {
    nombre = _nombre;
}
string EGO::getNombre() const {
    return nombre;
}
void EGO::setFolio(int _folio) {
    folio = _folio;
}
int EGO::getFolio() const {
    return folio;
}
void EGO::setFecha(const string& _fecha) {
    fecha = _fecha;
}
string EGO::getFecha() const {
    return fecha;
}
void EGO::setTipo(const string& _tipo) {
    tipo = _tipo;
}
string EGO::getTipo() const {
    return tipo;
}
string EGO::str() {
    stringstream sout;
    sout << "Nombre: " << nombre << "\nFolio: " << folio << "\nFecha: " << fecha << "\nTipo: " << tipo;
    return sout.str();
}


void EGO::guardarEnArchivo(ofstream& archivo) const {
    if (archivo.is_open()) {
        archivo << "Nombre del Paciente: " << nombre << endl;
        archivo << "Tipo de Examen: " << tipo << endl;
        // for (const auto& dato : ) {
        //     archivo << dato.first << ": " << dato.second << endl;
        // }
        archivo << "--------------------------" << endl << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
