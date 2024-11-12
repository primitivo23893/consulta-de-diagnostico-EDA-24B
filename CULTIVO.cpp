// Cultivo.cpp
#include "CULTIVO.h"

void Cultivo::ingresarDatos() {
    cout << "Ingrese el nombre del paciente: ";
    getline(cin, nombrePaciente);

    cout << "Ingrese el tipo de cultivo: ";
    getline(cin, tipoCultivo);

    while (true) {
        string atributo, valor;
        cout << "Ingrese el nombre del atributo: ";
        getline(cin, atributo);

        cout << "Ingrese el valor de " << atributo << ": ";
        getline(cin, valor);

        datos[atributo] = valor;

        char opcion;
        cout << "Desea agregar otro atributo? (s/n): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcion == 'n' || opcion == 'N') break;
    }
}

void Cultivo::mostrarDatos() const {
    cout << "Nombre del Paciente: " << nombrePaciente << endl;
    cout << "Tipo de Cultivo: " << tipoCultivo << endl;

    for (const auto& dato : datos) {
        cout << dato.first << ": " << dato.second << endl;
    }
    cout << "--------------------------" << endl;
}

void Cultivo::guardarEnArchivo(ofstream& archivo) const {
    if (archivo.is_open()) {
        archivo << "Nombre del Paciente: " << nombrePaciente << endl;
        archivo << "Tipo de Cultivo: " << tipoCultivo << endl;
        for (const auto& dato : datos) {
            archivo << dato.first << ": " << dato.second << endl;
        }
        archivo << "--------------------------" << endl << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
