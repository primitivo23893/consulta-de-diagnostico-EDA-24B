//hola
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Estructura para almacenar los datos de un análisis clínico
struct Analisis {
    int folio;
    string nombre;
    string fecha;
    string tipo;
};

// Lista para almacenar los análisis
Analisis analisisList[100]; // Arreglo estático para almacenar análisis
int analisisCount = 0; // Contador para la cantidad de análisis
int folioCounter = 1; // Contador para los folios

// Funciones de comparación sin distinción de mayúsculas y minúsculas
bool compararSinDistincion(const string &str1, const string &str2) {
    return equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
                [](char a, char b) { return tolower(a) == tolower(b); });
}

void setNombre(Analisis& analisis) {
    cout << "Ingrese su nombre: ";
    getline(cin, analisis.nombre);
}

void setFecha(Analisis& analisis) {
    cout << "Ingrese la fecha (DD/MM/AAAA): ";
    getline(cin, analisis.fecha);
}

void setTipo(Analisis& analisis) {
    cout << "Ingrese el tipo: ";
    getline(cin, analisis.tipo);
}

void registrar_analisis() {
    if (analisisCount >= 100) {
        cout << "No se pueden registrar mas analisis.\n";
        return;
    }

    Analisis nuevoAnalisis;
    nuevoAnalisis.folio = folioCounter++; // Generar folio automáticamente

    setNombre(nuevoAnalisis);
    setFecha(nuevoAnalisis);
    setTipo(nuevoAnalisis);

    char opcion;
    cout << "¿Desea guardar el registro? (S/N): ";
    cin >> opcion;
    cin.ignore(); // Limpiar el buffer de entrada

    if (opcion == 'S' || opcion == 's') {
        analisisList[analisisCount++] = nuevoAnalisis; // Agregar análisis a la lista
        cout << "Analisis registrado exitosamente. SU FOLIO ES: " << nuevoAnalisis.folio << endl;
    } else {
        cout << "Registro cancelado.\n";
    }
}

void consultar_analisis(int criterio_busqueda, const string& busqueda) {
    if (analisisCount == 0) {
        cout << "No hay analisis registrados. Por favor registre uno antes de buscar.\n";
        return;
    }

    if (criterio_busqueda == 1) {
        int folio = stoi(busqueda);
        for (int i = 0; i < analisisCount; ++i) {
            if (analisisList[i].folio == folio) {
                cout << "FOLIO: " << analisisList[i].folio << ", NOMBRE: " << analisisList[i].nombre
                    << ", FECHA: " << analisisList[i].fecha << ", TIPO: " << analisisList[i].tipo << endl;
                return;
            }
        }
        cout << "Analisis no encontrado.\n";
    } else {
        bool encontrado = false;
        for (int i = 0; i < analisisCount; ++i) {
            if ((criterio_busqueda == 2 && compararSinDistincion(analisisList[i].nombre, busqueda)) ||
                (criterio_busqueda == 3 && analisisList[i].fecha == busqueda) ||
                (criterio_busqueda == 4 && compararSinDistincion(analisisList[i].tipo, busqueda))) {
                cout << "FOLIO: " << analisisList[i].folio << ", NOMBRE: " << analisisList[i].nombre
                    << ", FECHA: " << analisisList[i].fecha << ", TIPO: " << analisisList[i].tipo << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "Analisis no encontrado.\n";
        }
    }
}

void eliminar_analisis(int criterio_busqueda, const string& busqueda) {
    if (analisisCount == 0) {
        cout << "No hay analisis registrados. Por favor registre uno antes de eliminar.\n";
        return;
    }

    char confirmacion;
    cout << "Esta seguro que desea eliminar el analisis? (S/N): ";
    cin >> confirmacion;
    cin.ignore(); // Limpiar el buffer de entrada

    if (confirmacion != 'S' && confirmacion != 's') {
        cout << "Eliminacion cancelada.\n";
        return;
    }

    if (criterio_busqueda == 1) {
        int folio = stoi(busqueda);
        for (int i = 0; i < analisisCount; ++i) {
            if (analisisList[i].folio == folio) {
                for (int j = i; j < analisisCount - 1; ++j) {
                    analisisList[j] = analisisList[j + 1]; // Desplazar elementos hacia la izquierda
                }
                analisisCount--;
                cout << "Analisis eliminado exitosamente.\n";
                return;
            }
        }
        cout << "Analisis no encontrado.\n";
    } else {
        for (int i = 0; i < analisisCount; ++i) {
            if ((criterio_busqueda == 2 && compararSinDistincion(analisisList[i].nombre, busqueda)) ||
                (criterio_busqueda == 3 && analisisList[i].fecha == busqueda) ||
                (criterio_busqueda == 4 && compararSinDistincion(analisisList[i].tipo, busqueda))) {
                for (int j = i; j < analisisCount - 1; ++j) {
                    analisisList[j] = analisisList[j + 1]; // Desplazar elementos hacia la izquierda
                }
                analisisCount--;
                cout << "Analisis eliminado exitosamente.\n";
                return;
            }
        }
        cout << "Analisis no encontrado.\n";
    }
}

void editar_analisis(int criterio_busqueda, const string& busqueda) {
    if (analisisCount == 0) {
        cout << "No hay analisis registrados. Por favor registre uno antes de editar.\n";
        return;
    }

    if (criterio_busqueda == 1) {
        int folio = stoi(busqueda);
        for (int i = 0; i < analisisCount; ++i) {
            if (analisisList[i].folio == folio) {
                cout << "EDITANDO ANALISIS FOLIO: " << analisisList[i].folio << endl;
                setNombre(analisisList[i]);
                setFecha(analisisList[i]);
                setTipo(analisisList[i]);

                char opcion;
                cout << "¿Desea guardar los cambios? (S/N): ";
                cin >> opcion;
                cin.ignore(); // Limpiar el buffer de entrada

                if (opcion == 'S' || opcion == 's') {
                    cout << "Analisis editado exitosamente.\n";
                } else {
                    cout << "Edicion cancelada.\n";
                }
                return;
            }
        }
        cout << "Analisis no encontrado.\n";
    } else {
        for (int i = 0; i < analisisCount; ++i) {
            if ((criterio_busqueda == 2 && compararSinDistincion(analisisList[i].nombre, busqueda)) ||
                (criterio_busqueda == 3 && analisisList[i].fecha == busqueda) ||
                (criterio_busqueda == 4 && compararSinDistincion(analisisList[i].tipo, busqueda))) {
                cout << "EDITANDO ANALISIS FOLIO: " << analisisList[i].folio << endl;
                setNombre(analisisList[i]);
                setFecha(analisisList[i]);
                setTipo(analisisList[i]);

                char opcion;
                cout << "¿Desea guardar los cambios? (S/N): ";
                cin >> opcion;
                cin.ignore(); // Limpiar el buffer de entrada

                if (opcion == 'S' || opcion == 's') {
                    cout << "Analisis editado exitosamente.\n";
                } else {
                    cout << "Edicion cancelada.\n";
                }
                return;
            }
        }
        cout << "Analisis no encontrado.\n";
    }
}

void ordenar_analisis(int criterio_orden) {
    if (analisisCount == 0) {
        cout << "No hay analisis registrados.\n";
        return;
    }

    switch (criterio_orden) {
        case 1:
            sort(analisisList, analisisList + analisisCount, [](const Analisis& a, const Analisis& b) {
                return a.folio < b.folio;
            });
            break;
        case 2:
            sort(analisisList, analisisList + analisisCount, [](const Analisis& a, const Analisis& b) {
                return a.nombre < b.nombre;
            });
            break;
        case 3:
            sort(analisisList, analisisList + analisisCount, [](const Analisis& a, const Analisis& b) {
                return a.fecha < b.fecha;
            });
            break;
        case 4:
            sort(analisisList, analisisList + analisisCount, [](const Analisis& a, const Analisis& b) {
                return a.tipo < b.tipo;
            });
            break;
        default:
            cout << "Criterio de ordenamiento invalido.\n";
            return;
    }

    cout << "Analisis ordenados exitosamente:\n";
    for (int i = 0; i < analisisCount; ++i) {
        cout << "FOLIO: " << analisisList[i].folio << ", NOMBRE: " << analisisList[i].nombre
            << ", FECHA: " << analisisList[i].fecha << ", TIPO: " << analisisList[i].tipo << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "\nMENU DE ANALISIS CLINICOS\n";
        cout << "1. REGISTRAR ANALISIS\n";
        cout << "2. CONSULTAR ANALISIS\n";
        cout << "3. EDITAR ANALISIS\n";
        cout << "4. ELIMINAR ANALISIS\n";
        cout << "5. ORDENAR ANALISIS\n";
        cout << "6. SALIR\n";
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                registrar_analisis();
                break;
            case 2: {
                int criterio_busqueda;
                string busqueda;

                cout << "Criterios de busqueda:\n";
                cout << "1. Folio\n";
                cout << "2. Nombre\n";
                cout << "3. Fecha\n";
                cout << "4. Tipo\n";
                cout << "Seleccione el criterio: ";
                cin >> criterio_busqueda;
                cin.ignore(); // Limpiar el buffer de entrada

                cout << "Ingrese la busqueda: ";
                getline(cin, busqueda);

                consultar_analisis(criterio_busqueda, busqueda);
                break;
            }
            case 3: {
                int criterio_busqueda;
                string busqueda;

                cout << "Criterios de busqueda:\n";
                cout << "1. Folio\n";
                cout << "2. Nombre\n";
                cout << "3. Fecha\n";
                cout << "4. Tipo\n";
                cout << "Seleccione el criterio: ";
                cin >> criterio_busqueda;
                cin.ignore(); // Limpiar el buffer de entrada

                cout << "Ingrese la busqueda: ";
                getline(cin, busqueda);

                editar_analisis(criterio_busqueda, busqueda);
                break;
            }
            case 4: {
                int criterio_busqueda;
                string busqueda;

                cout << "Criterios de busqueda:\n";
                cout << "1. Folio\n";
                cout << "2. Nombre\n";
                cout << "3. Fecha\n";
                cout << "4. Tipo\n";
                cout << "Seleccione el criterio: ";
                cin >> criterio_busqueda;
                cin.ignore(); // Limpiar el buffer de entrada

                cout << "Ingrese la busqueda: ";
                getline(cin, busqueda);

                eliminar_analisis(criterio_busqueda, busqueda);
                break;
            }
            case 5: {
                int criterio_orden;
                cout << "Criterios de ordenamiento:\n";
                cout << "1. Folio\n";
                cout << "2. Nombre\n";
                cout << "3. Fecha\n";
                cout << "4. Tipo\n";
                cout << "Seleccione el criterio: ";
                cin >> criterio_orden;
                cin.ignore(); // Limpiar el buffer de entrada

                ordenar_analisis(criterio_orden);
                break;
            }
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Por favor intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
