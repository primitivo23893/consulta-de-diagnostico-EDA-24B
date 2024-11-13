#include "QS.h"

QS::QS() {
    nombre = "";
    fecha = "";
    tipo = "";
    folio = 0;
}
void QS::setNombre(const string& _nombre) {
    nombre = _nombre;
}
string QS::getNombre() const {
    return nombre;
}
void QS::setFolio(int _folio) {
    folio = _folio;
}
int QS::getFolio() const {
    return folio;
}
void QS::setFecha(const string& _fecha) {
    fecha = _fecha;
}
string QS::getFecha() const {
    return fecha;
}
void QS::setTipo(const string& _tipo) {
    tipo = _tipo;
}
string QS::getTipo() const {
    return tipo;
}
string QS::str() {
    stringstream sout;
    sout << "Nombre: " << nombre << "\nFolio: " << folio << "\nFecha: " << fecha << "\nTipo: " << tipo;
    return sout.str();
}

void QS::addComponente(Componente* componente) {
    componentes.agregarFinal(componente);
}
void QS::removeComponente(int pos) {
    componentes.eliminarPosicion(pos);
}
void QS::editarComponente(int pos, Componente* componente) {
    if (pos < 0 || pos >= componentes.getTamano()) {
        cout << "Posición inválida" << endl;
        return;
    }

    Nodo<Componente>* actual = componentes.getInicio();
    for (int i = 0; i < pos; ++i) {
        actual = actual->siguiente;
    }

    if (actual != nullptr) {
        actual->dato = componente;
    }
}

void QS::guardarEnArchivo(ofstream& archivo) const {
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
