#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <sstream>

using namespace std;

class Ego {
public:
    string nombrePaciente;
    string tipoEgo;
    map<string, string> datos;

    void ingresarDatos();
    void mostrarDatos() const;
    void guardarEnArchivo(ofstream& archivo) const;
    string str() const; // Nueva función para devolver los datos como string
};

// Clase Nodo para la lista simplemente enlazada
template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

// Clase ListaEnlazada que maneja nodos de cualquier tipo de dato (genérica)
template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    // Método para agregar un nuevo elemento al final de la lista
    void agregar(const T& nuevoDato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(nuevoDato);
        if (!cabeza) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    // Método para mostrar todos los datos en la lista
    void mostrar() const {
        Nodo<T>* temp = cabeza;
        while (temp) {
            cout << temp->dato.str() << endl;  // Usamos str() en lugar de mostrarDatos()
            temp = temp->siguiente;
        }
    }

    // Método para guardar todos los datos de la lista en un archivo
    void guardarEnArchivo() const {
        ofstream archivo("ego_clinicos.txt", ios::app);
        if (archivo.is_open()) {
            Nodo<T>* temp = cabeza;
            while (temp) {
                archivo << temp->dato.str() << endl;  // Usamos str() para el archivo
                temp = temp->siguiente;
            }
            archivo.close();
            cout << "Todos los egos se han guardado exitosamente en el archivo.\n";
        } else {
            cout << "No se pudo abrir el archivo para guardar los egos.\n";
        }
    }
};

// Implementación de la función str()
string Ego::str() const {
    stringstream sout;
    sout << "Nombre del Paciente: " << nombrePaciente << "\n";
    sout << "Tipo de EGO: " << tipoEgo << "\n";

    for (const auto& dato : datos) {
        sout << dato.first << ": " << dato.second << "\n";
    }
    sout << "--------------------------";
    return sout.str();
}

// Implementación de métodos de la clase Ego
void Ego::ingresarDatos() {
    cout << "Ingrese el nombre del paciente: ";
    getline(cin, nombrePaciente);

    cout << "Ingrese el tipo de EGO: ";
    getline(cin, tipoEgo);

    while (true) {
        string atributo, valor;
        cout << "Ingrese el nombre del atributo: ";
        getline(cin, atributo);

        cout << "Ingrese el valor de " << atributo << ": ";
        getline(cin, valor);

        datos[atributo] = valor;

        char opcion;
        cout << "¿Desea agregar otro atributo? (s/n): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpia el buffer de entrada

        if (opcion == 'n' || opcion == 'N') break;
    }
}

void Ego::mostrarDatos() const {
    cout << str() << endl;  // Usa la función str() para mostrar datos formateados
}

void Ego::guardarEnArchivo(ofstream& archivo) const {
    if (archivo.is_open()) {
        archivo << str() << endl;  // Usa la función str() para guardar en el archivo
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main() {
    ListaEnlazada<Ego> listaEgos;
    char opcion;

    do {
        Ego nuevoEgo;
        nuevoEgo.ingresarDatos();
        listaEgos.agregar(nuevoEgo);

        cout << "¿Desea agregar otro EGO? (s/n): ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpia el buffer de entrada
    } while (opcion == 's' || opcion == 'S');

    cout << "\n=== Resumen de EGO ===\n";
    listaEgos.mostrar();
    listaEgos.guardarEnArchivo();

    return 0;
}
