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
void eliminarAnalisis(Menu& menu);
void ordenarAnalisis(Menu& menu);
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
            eliminarAnalisis(*this);
            break;
        case 5:
            ordenarAnalisis(*this);
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

AnalisisBase& Menu::getAnalisisBase() {
    return analisisBase;
}

void registroAnalisis(Menu& menu) {
    int opc;
    bool seguir = true;
    do {
        system(CLEAR);
        cout << ">> Registro de Análisis <<" << endl;
        cout << "Selecciona el tipo de análisis a registrar:" << endl;
        cout << "1. EGO" << endl;
        cout << "2. QS" << endl;
        cout << "3. Cultivo" << endl;
        cout << "\nSeleccione una opción: ";
        cin >> opc;
        cin.ignore();
        if(opc != 1 && opc != 2 && opc != 3){
            cout << "Opción no válida. Intente nuevamente." << endl;
        } else {
            seguir = false;
        }
    } while (seguir);
    system(CLEAR);
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
    int folio;
    cout << ">> Consultar analisis<<" << endl;
    cout << "Ingrese el folio del analisis a consultar: " << endl;
    cin >> folio;
    cin.ignore();
    

}

void editarAnalisis() {
    cout << "Editando análisis..." << endl;
    // Agregar aquí la lógica para editar un análisis
}

void eliminarAnalisis(Menu& menu) {
    int folio;
    system(CLEAR);
    cout << ">> Eliminar Analisis <<" << endl;
    cout << "Ingrese el folio del análisis a eliminar: ";
    cin >> folio;
    cin.ignore();
    int pos = menu.getAnalisisBase().buscarPorFolio(folio);
    if (pos == -1) {
        cout << "No se encontró el análisis con el folio proporcionado." << endl;
        return;
    }else{
        system(CLEAR);
        cout << "Análisis encontrado: " << endl;
        cout << menu.getAnalisisBase().mostrarPorFolio(folio);
        auto ayuda = &menu.getAnalisisBase();
        cout << "\n¿Qué desea eliminar?" << endl;
        cout << "1. Eliminar analisis"<<endl;
        cout << "2. Elimiar componente"<<endl;
        cout << "3. Cancelar"<<endl;
        cout << "Seleccione una opción: ";
        int opc;
        cin >> opc;
        cin.ignore();
        if(opc == 1){
            cout << "¿Está seguro de eliminar el análisis? (s/n): ";
            char opc1;
            cin >> opc1;
            cin.ignore();
            if(opc1 == 's' || opc1 == 'S'){

            menu.getAnalisisBase().removeAnalisis(pos);
            cout << "\nAnálisis eliminado correctamente." << endl;

            }else{
                cout << "Operación cancelada." << endl;

            }
        }else if(opc == 2){
            cout << "Ingrese el nombre del componente a eliminar: ";
            string nombre;
            getline(cin, nombre);
            cout << nombre << endl;
            int pos = ayuda->buscarComponentePorNombre(nombre);
            if(pos == -1){
                cout << "No se encontró el componente con el nombre proporcionado."<< endl;
                return;
            }
            cout << "Componente encontrado: " << endl;
            cout << ayuda->mostrarComponente(pos);
            cout << "¿Está seguro de eliminar el componente? (s/n): ";
            char opc2;
            cin >> opc2;
            cin.ignore();
            if(opc2 == 's' || opc2 == 'S'){

                ayuda->removeComponente(pos);
                cout << "Componente eliminado correctamente." << endl;

            }else{
                cout << "Operación cancelada." << endl;

            }
        }else{
            cout << "Operación cancelada." << endl;

        }
    }
    // Agregar aquí la lógica para eliminar un análisis
}

void ordenarAnalisis(Menu& menu) {
    int opcion;
    system(CLEAR);
    cout << ">> Ordenar Analisis<<" << endl;
    cout << "Seleccione el criterio de ordenamiento:" << endl;
    cout << "1. Por nombre" << endl;
    cout << "2. Por fecha" << endl;
    cout << "3. Por tipo" << endl;
    cout << "4. Por folio" << endl;
    cout << "Seleccione una opción: ";
    do {
        cin >> opcion;
        cin.ignore();
        if (opcion < 1 || opcion > 4) {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion < 1 || opcion > 4);

    switch (opcion) {
    case 1:
        // Ordenar por nombre
        break;
    case 2:
        // Ordenar por fecha
        break;
    case 3:
        // Ordenar por tipo
        break;
    case 4:
        // Ordenar por folio
        system(CLEAR);
        cout << "Analisis ordenados por folio: " << endl;
        cout << menu.getAnalisisBase().mostrarTodo();
        break;
    // Agregar aquí la lógica para ordenar los análisis
    }
    
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
