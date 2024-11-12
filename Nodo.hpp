template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

// Clase ListaEnlazada que maneja nodos de cualquier tipo de dato (gen�rica)
template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
public:
    ListaEnlazada() : cabeza(nullptr) {}

    // Metodo para agregar un nuevo elemento al final de la lista
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

    // Metodo para mostrar todos los datos en la lista
    void mostrar() const {
        Nodo<T>* temp = cabeza;
        while (temp) {
            temp->dato.mostrarDatos();
            temp = temp->siguiente;
        }
    }

    // Metodo para guardar todos los datos de la lista en un archivo
    void guardarEnArchivo() const {
        ofstream archivo("cultivos_clinicos.txt", ios::app);
        if (archivo.is_open()) {
            Nodo<T>* temp = cabeza;
            while (temp) {
                temp->dato.guardarEnArchivo(archivo);
                temp = temp->siguiente;
            }
            archivo.close();
            cout << "Todos los cultivos se han guardado exitosamente en el archivo.\n";
        } else {
            cout << "No se pudo abrir el archivo para guardar los cultivos.\n";
        }
    }
};