#include "Cultivo.h"

Cultivo::Cultivo() {
    nombre = "";
    fecha = "";
    tipo = "";
    folio = 0;
}

void Cultivo::setNombre(const string& _nombre) {
    nombre = _nombre;
}

string Cultivo::getNombre() const {
    return nombre;
}

void Cultivo::setFolio(int _folio) {
    folio = _folio;
}

int Cultivo::getFolio() const {
    return folio;
}

void Cultivo::setFecha(const string& _fecha) {
    fecha = _fecha;
}

string Cultivo::getFecha() const {
    return fecha;
}

void Cultivo::setTipo(const string& _tipo) {
    tipo = _tipo;
}

string Cultivo::getTipo() const {
    return tipo;
}

string Cultivo::str() {
    stringstream sout;
    sout << "Nombre: " << nombre << "\nFolio: " << folio << "\nFecha: " << fecha << "\nTipo: " << tipo;
    return sout.str();
}

void Cultivo::addComponente(Componente* componente) {
    componentes.agregarFinal(componente);
}

void Cultivo::removeComponente(int pos) {
    componentes.eliminarPosicion(pos);
}

void Cultivo::editarComponente(int pos, Componente* componente) {
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

void Cultivo::guardarEnArchivo(ofstream& archivo) const {
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
