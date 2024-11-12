#include "Analisis.h"
#include <fstream>
#include <sstream>


Analisis :: Analisis() {

}

void Analisis::addEGO() {

}

void Analisis::removeEGO() {

}

void Analisis::addQS() {

}

void Analisis::removeQS() {

}

void Analisis::addCultivo() {

}

void Analisis::removeCultivo() {

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
        archivo << str();
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
    cout << str();
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