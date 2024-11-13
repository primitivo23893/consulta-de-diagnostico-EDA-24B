#include "menu.h"
#include <Analisis.h>
//#include "Cultivo.h"

#include <iostream>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"  // Comando para limpiar pantalla en Windows
#else
#define CLEAR "clear"  // Comando para limpiar pantalla en otros SO
#endif

void registroAnalisis();
void consultarAnalisis();
void editarAnalisis();
void eliminarAnalisis();
void ordenarAnalisis();
void registroEgo();
void registroQS();
void registroCultivo();
void mostrarMenu();

Menu::Menu() {
    folioGlobal = 1;
    bool seguir = true;
    int opc;

    do {
        system(CLEAR); // Borra toda la pantalla
        mostrarMenu();
        cin >> opc;
        cin.ignore();  // Ignorar el salto de línea después de la selección

        switch (opc) {
        case 1:
            registroAnalisis();
            break;
        case 2:
            consultarAnalisis();
            break;
        case 3:
            editarAnalisis();
            break;
        case 4:
            eliminarAnalisis();
            break;
        case 5:
            ordenarAnalisis();
            break;
        case 6:
            seguir = false;  // Termina el programa
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            break;
        }

        if (seguir) {
            cout << "Presione Enter para continuar..." << endl;
            cin.get();  // Pausa antes de mostrar el menú nuevamente
        }

    } while (seguir);
}

int Menu::getFolio() {
    return folioGlobal;
}

void Menu::incrementarFolio() {
    folioGlobal++;
}

void Menu::setFolio(int folio) {
    folioGlobal = folio;
}

// Función para registrar un nuevo análisis de cultivo
void registroAnalisis() {
    int opc;
    string nombre;
    string fecha;
    bool seguir = true;
    do
    {
        cout << "Selecciona el tipo de análisis a registrar:" << endl;
        cout << "1. EGO" << endl;
        cout << "2. QS" << endl;
        cout << "3. Cultivo" << endl;
        cin >> opc;
        cin.ignore();
        if(opc != 1 && opc != 2 && opc != 3){
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
        else
        {
            seguir = false;
        }
    } while (seguir);
    switch (opc)
    {
    case 1:
        registroEgo();
        break;
    case 2:
        registroAnalisis();
        break;
    case 3:
        registroCultivo();
        break;
    default:
        break;
    }

   // Cultivo cultivo;
    string nombre;

    cout << "Dame tu nombre: ";
    getline(cin, nombre);

    // Aquí puedes agregar más lógica para el registro del cultivo
    cout << "Registro de análisis completado para " << nombre << "." << endl;
}

// Función para consultar análisis
void consultarAnalisis() {
    cout << "Consultando análisis..." << endl;
    // Agregar aquí la lógica para consultar los análisis
}

// Función para editar un análisis existente
void editarAnalisis() {
    cout << "Editando análisis..." << endl;
    // Agregar aquí la lógica para editar un análisis
}

// Función para eliminar un análisis
void eliminarAnalisis() {
    cout << "Eliminando análisis..." << endl;
    // Agregar aquí la lógica para eliminar un análisis
}

// Función para ordenar análisis
void ordenarAnalisis() {
    cout << "Ordenando análisis..." << endl;
    // Agregar aquí la lógica para ordenar los análisis
}
void registroEgo(){
    cout << "Registrando análisis de EGO..." << endl;
    cout << "Nombre del paciente: ";
    string nombre;
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    string fecha;
    getline(cin, fecha);

    EGO ego;
    ego.setNombre(nombre);
    ego.setFecha(fecha);
    ego.setTipo("EGO");
    ego.setFolio(Menu().getFolio());
    Menu().incrementarFolio();
}
void registroQS(){
    cout << "Registrando análisis de QS..." << endl;
    cout << "Nombre del paciente: ";
    string nombre;
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    string fecha;
    getline(cin, fecha);

    QS qs;
    qs.setNombre(nombre);
    qs.setFecha(fecha);
    qs.setTipo("QS");
    qs.setFolio(Menu().getFolio());
    Menu().incrementarFolio();
}
void registroCultivo(){
    cout << "Registrando análisis de Cultivo..." << endl;
    cout << "Nombre del paciente: ";
    string nombre;
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    string fecha;
    getline(cin, fecha);

    Cultivo cultivo;
    cultivo.setNombre(nombre);
    cultivo.setFecha(fecha);
    cultivo.setTipo("Cultivo");
    cultivo.setFolio(Menu().getFolio());
    Menu().incrementarFolio();
}
// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "=== Menú Principal ===" << endl;
    cout << "1. Registrar análisis" << endl;
    cout << "2. Consultar análisis" << endl;
    cout << "3. Editar análisis" << endl;
    cout << "4. Eliminar análisis" << endl;
    cout << "5. Ordenar análisis" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}
