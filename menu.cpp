#include "menu.h"
#include "EGO.h"
#include "QS.h"
#include "Cultivo.h"

#include <iostream>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"  // Comando para limpiar pantalla en Windows
#else
#define CLEAR "clear"  // Comando para limpiar pantalla en otros SO
#endif

void registroAnalisis(Menu& menu);
void consultarAnalisis(Menu& menu);
void editarAnalisis();
void eliminarAnalisis();
void ordenarAnalisis();
void registroEgo(Menu& menu);
void registroQS(Menu& menu);
void registroCultivo(Menu& menu);
void agregarComponente(AnalisisBase& analisisBase);
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
            registroAnalisis(*this);
            break;
        case 2:
            consultarAnalisis(*this);
            cin.get();
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

AnalisisBase Menu::getAnalisisBase() {
    return analisisBase;
}

void registroAnalisis(Menu& menu) {
    int opc;
    bool seguir = true;
    do {
        cout << "Selecciona el tipo de análisis a registrar:" << endl;
        cout << "1. EGO" << endl;
        cout << "2. QS" << endl;
        cout << "3. Cultivo" << endl;
        cin >> opc;
        cin.ignore();
        if(opc != 1 && opc != 2 && opc != 3){
            cout << "Opción no válida. Intente nuevamente." << endl;
        } else {
            seguir = false;
        }
    } while (seguir);

    switch (opc) {
    case 1:
        registroEgo(menu);
        break;
    case 2:
        registroQS(menu);
        break;
    case 3:
        registroCultivo(menu);
        break;
    default:
        break;
    }
}

void registroEgo(Menu& menu) {
    string nombre;
    string fecha;
    cout << "Registrando análisis de EGO..." << endl;
    cout << "Nombre del paciente: ";
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    getline(cin, fecha);

    EGO* ego = new EGO();
    ego->setNombre(nombre);
    ego->setFecha(fecha);
    ego->setFolio(menu.getFolio());
    menu.incrementarFolio();
    agregarComponente(*ego);
    menu.getAnalisisBase().addAnalisis(ego);
}

void registroQS(Menu& menu) {
    string nombre;
    string fecha;
    cout << "Registrando análisis de QS..." << endl;
    cout << "Nombre del paciente: ";
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    getline(cin, fecha);

    QS* qs = new QS();
    qs->setNombre(nombre);
    qs->setFecha(fecha);
    qs->setFolio(menu.getFolio());
    menu.incrementarFolio();
    
    agregarComponente(*qs);
    menu.getAnalisisBase().addAnalisis(qs);
}

void registroCultivo(Menu& menu) {
    string nombre;
    string fecha;
    cout << "Registrando análisis de Cultivo..." << endl;
    cout << "Nombre del paciente: ";
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    getline(cin, fecha);

    Cultivo* cultivo = new Cultivo();
    cultivo->setNombre(nombre);
    cultivo->setFecha(fecha);
    cultivo->setFolio(menu.getFolio());
    menu.incrementarFolio();
    agregarComponente(*cultivo);
    menu.getAnalisisBase().addAnalisis(cultivo);
}
void agregarComponente(AnalisisBase& analisisBase){
    string nombre;
    string valor;
    string rango;
    char opc;
    do{
        cout << "Nombre del componente: ";
        getline(cin, nombre);
        cout << "Valor del componente: ";
        getline(cin, valor);
        cout << "Rango del componente: ";
        getline(cin, rango);
        analisisBase.addComponente(new Componente(nombre, valor, rango));
        cout << "¿Desea agregar otro componente? (s/n): ";
        cin >> opc;
        cin.ignore();
    } while(opc == 's' || opc == 'S');
}
void consultarAnalisis(Menu& menu) {
    cout << "Consultando análisis..." << endl;
    cout << menu.getAnalisisBase().mostrarTodo();
}

void editarAnalisis() {
    cout << "Editando análisis..." << endl;
    // Agregar aquí la lógica para editar un análisis
}

void eliminarAnalisis() {
    cout << "Eliminando análisis..." << endl;
    // Agregar aquí la lógica para eliminar un análisis
}

void ordenarAnalisis() {
    cout << "Ordenando análisis..." << endl;
    // Agregar aquí la lógica para ordenar los análisis
}

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
