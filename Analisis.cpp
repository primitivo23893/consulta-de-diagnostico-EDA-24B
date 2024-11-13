#include "Analisis.h"
#include "EGO.h"
#include "QS.h"
#include "Cultivo.h"
#include <fstream>
#include <sstream>

Analisis::Analisis() {
    listaAnalisis = new ListaEnlazada<AnalisisBase>();
}

Analisis::~Analisis() {
    delete listaAnalisis;
}

void Analisis::addEGO(EGO* ego) {
    listaAnalisis->agregarFinal(ego);
}

void Analisis::removeEGO(int pos) {
    listaAnalisis->eliminarPosicion(pos);
}

void Analisis::addQS(QS* qs) {
    listaAnalisis->agregarFinal(qs);
}

void Analisis::removeQS(int pos) {
    listaAnalisis->eliminarPosicion(pos);
}

void Analisis::addCultivo(Cultivo* cultivo) {
    listaAnalisis->agregarFinal(cultivo);
}

void Analisis::removeCultivo(int pos) {
    listaAnalisis->eliminarPosicion(pos);
}

// Métodos de ordenamiento

void Analisis::ordenarTipo() {

}

void Analisis::ordenarFecha() {

}

void Analisis::ordenarFolio() {

}

void Analisis::ordenarAlfabeto() {

}

// Métodos para manejo de archivo

void Analisis::guardarEnArchivo() const {
    ofstream archivo("analisis_clinicos.txt", ios::app);
    if (archivo.is_open()) {
        Nodo<AnalisisBase>* temp = listaAnalisis->getInicio();
        while (temp) {
            temp->dato->guardarEnArchivo(archivo);
            temp = temp->siguiente;
        }
        archivo.close();
        cout << "Datos guardados en el archivo correctamente.\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos.\n";
    }
}

void Analisis::recuperarDeArchivo() {
    ifstream archivo("analisis_clinicos.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer los datos.\n";
    }
}

void Analisis::mostrarTodo() const {
    Nodo<AnalisisBase>* temp = listaAnalisis->getInicio();
    while (temp) {
        cout << temp->dato->str() << endl;
        temp = temp->siguiente;
    }
}

string Analisis::str() const {
    stringstream sout;
    sout << "Lista de Análisis Clínicos:\n";
    // Aquí iría la iteración de los elementos de la lista enlazada y su conversión a cadena se se emplea
    // Ejemplo:
    // for (const auto& item : lista) {
    //     sout << item.str() << "\n";
    // }
    return sout.str();
}