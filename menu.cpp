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
void editarAnalisis(Menu& menu);
void eliminarAnalisis(Menu& menu);
void ordenarAnalisis(Menu& menu);
void registroEgo(Menu& menu);
void registroQS(Menu& menu);
void registroCultivo(Menu& menu);
void agregarComponente(AnalisisBase& analisisBase);
void mostrarMenu();
void a(Menu& menu);
Menu::Menu() {
    folioGlobal = 1;
    bool seguir = true;
    int opc;
    a(*this);
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
            
            break;
        case 3:
            editarAnalisis(*this);
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

const vector<std::unique_ptr<AnalisisBase>>& Menu::getListaAnalisis() const {
    return listaAnalisis;
}
vector<std::unique_ptr<AnalisisBase>>& Menu::getListaAnalisis() {
    return listaAnalisis;
}

void registroAnalisis(Menu& menu) {
    int opc;
    bool seguir = true;
    do {
        system(CLEAR);
        cout << ">> Registro de Análisis <<" << endl;
        cout << "Selecciona el tipo de análisis a registrar:" << endl;
        cout << "1. Examen General de Orina (EGO)." << endl;
        cout << "2. Quimica Sanguinea (QS)" << endl;
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
    
    cout << ">Registrando análisis de Examen General de Orina (EGO) <" << endl<<endl;
    cout << "Nombre del paciente: ";
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    getline(cin, fecha);

    unique_ptr<EGO> ego = make_unique<EGO>();
    ego->setNombre(nombre);
    ego->setFecha(fecha);
    ego->setFolio(menu.getFolio());
    menu.incrementarFolio();
    agregarComponente(*ego);
    menu.getListaAnalisis().emplace_back(std::move(ego));
    cout << "Análisis registrado correctamente con el Folio: "<<menu.getFolio()-1 << endl;
}

void registroQS(Menu& menu) {
    string nombre;
    string fecha;
    cout << ">Registrando análisis de Quimica Sanguinea (QS) <" << endl << endl;
    cout << "Nombre del paciente: ";
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    getline(cin, fecha);

    unique_ptr<QS> qs = make_unique<QS>();
    qs->setNombre(nombre);
    qs->setFecha(fecha);
    qs->setFolio(menu.getFolio());
    menu.incrementarFolio();
    
    agregarComponente(*qs);
    menu.getListaAnalisis().emplace_back(std::move(qs));
    cout << "Análisis registrado correctamente con el Folio: "<<menu.getFolio()-1 << endl;
}

void registroCultivo(Menu& menu) {
    string nombre;
    string fecha;
    cout << "> Registrando análisis de Cultivo <" << endl << endl;
    cout << "Nombre del paciente: ";
    getline(cin, nombre);
    cout << "Fecha de realización: ";
    getline(cin, fecha);

    unique_ptr<Cultivo> cultivo = make_unique<Cultivo>();
    cultivo->setNombre(nombre);
    cultivo->setFecha(fecha);
    cultivo->setFolio(menu.getFolio());
    menu.incrementarFolio();
    agregarComponente(*cultivo);
    menu.getListaAnalisis().emplace_back(std::move(cultivo));
    //cout
}
void agregarComponente(AnalisisBase& analisisBase){
    string nombre;
    string valor;
    string rango;
    char opc;
    do{
        system(CLEAR);
        cout << "> Agregar Componente <" << endl << endl;
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

int buscarPorFolio(Menu& menu, int folio) {
    for (int i = 0; i < menu.getListaAnalisis().size(); i++) {
        if (menu.getListaAnalisis()[i]->getFolio() == folio) {
            return i;
        }
    }
    return -1;
}

string mostrarPorFolio(Menu& menu,int folio) {
    int pos = buscarPorFolio(menu, folio);
    if (pos == -1) {
        return "No se encontró el análisis con el folio proporcionado.";
    }
    return menu.getListaAnalisis()[pos]->str();
}

void consultarAnalisis(Menu& menu) {
    int folio;
    system(CLEAR);
    cout << ">> Consultar analisis<<" << endl;
    cout << "Ingrese el folio del analisis a consultar: " << endl;
    cin >> folio;
    cin.ignore();
    int pos = buscarPorFolio(menu, folio);
    if (pos == -1) {
        cout << "No se encontró el análisis con el folio proporcionado." << endl;
    } else {
        cout << "Análisis encontrado: " << endl;
        cout << mostrarPorFolio(menu, folio);
    }
    

}

void editarAnalisis(Menu& menu) {
    system(CLEAR);
    cout << ">> Editar Analisis <<" << endl;
    cout << "Ingrese el folio del análisis a editar: ";
    int folio;
    cin >> folio;
    cin.ignore();
    int pos = buscarPorFolio(menu, folio);
    if (pos == -1) {
        cout << "No se encontró el análisis con el folio proporcionado." << endl;
        return;
    } else {
        system(CLEAR);
        cout << "Análisis encontrado: " << endl;
        cout << mostrarPorFolio(menu, folio);
        cout << "\n¿Qué desea editar?" << endl;
        cout << "1. Editar análisis" << endl;
        cout << "2. Editar componente" << endl;
        cout << "3. Cancelar" << endl;
        cout << "Seleccione una opción: ";
        int opc;
        cin >> opc;
        cin.ignore();
        if (opc == 1) {
            string nombre;
            string fecha;
            string tipo;
            system(CLEAR);
            cout << "Analisis a Editar" << endl;
            cout << mostrarPorFolio(menu, folio);
            // Guardar los datos anteriores
            auto& analisis = menu.getListaAnalisis()[pos];
            string nombreAnterior = analisis->getNombre();
            string fechaAnterior = analisis->getFecha();
            string tipoAnterior = analisis->getTipo();
            cout << "Este es el valor antiguo de nombre: " << nombreAnterior << endl;
            cout << "Este es el valor antiguo de fecha: " << fechaAnterior << endl;
            cout << "Este es el valor antiguo de tipo: " << tipoAnterior << endl;

            // Editar los datos
            cout << "Ingrese los nuevos datos del análisis:" << endl;
            cout << "\t\t\t\t\tNota: Si no desea editar un campo, coloque -1." << endl;
            cout << endl << "Nuevo nombre: ";
            getline(cin, nombre);
            cout << "Fecha de realización: ";
            getline(cin, fecha);
            cout << "Nuevo tipo (EGO, QS, Cultivo): ";
            getline(cin, tipo);

            // Crear un nuevo análisis
            unique_ptr<AnalisisBase> nuevoAnalisis;
            if(tipo == "-1") {
                tipo = tipoAnterior;
            }
            if (tipo == "EGO") {
                nuevoAnalisis = make_unique<EGO>();
            } else if (tipo == "QS") {
                nuevoAnalisis = make_unique<QS>();
            } else if (tipo == "Cultivo") {
                nuevoAnalisis = make_unique<Cultivo>();
            } else {
                cout << "Tipo de análisis no válido." << endl;
                return;
            }
            // Editar los datos
            if (nombre == "-1") {
                nuevoAnalisis->setNombre(nombreAnterior);
            } else {
                nuevoAnalisis->setNombre(nombre);
            }

            if (fecha == "-1") {
                nuevoAnalisis->setFecha(fechaAnterior);
            } else {
                nuevoAnalisis->setFecha(fecha);
            }
            nuevoAnalisis->setFolio(folio);

            // Copiar los componentes del análisis anterior al nuevo
            for (const auto& componente : analisis->getComponentes()) {
                nuevoAnalisis->addComponente(new Componente(componente));
            }

            menu.getListaAnalisis()[pos] = std::move(nuevoAnalisis);

            cout << "Análisis editado correctamente." << endl;
        } else if (opc == 2) {
            cout << "Ingrese el nombre del componente a editar: ";
            string nombre;
            getline(cin, nombre);
            auto& analisis = *menu.getListaAnalisis()[pos];
            int posComponente = analisis.buscarComponentePorNombre(nombre);
            if (posComponente == -1) {
                cout << "No se encontró el componente con el nombre proporcionado." << endl;
                return;
            }
            cout << "Componente encontrado: " << endl;
            cout << analisis.mostrarComponente(posComponente);
            cout << "Ingrese el nuevo nombre del componente: ";
            string nombreNuevo;
            getline(cin, nombreNuevo);
            cout << "Ingrese el nuevo valor del componente: ";
            string valorNuevo;
            getline(cin, valorNuevo);
            cout << "Ingrese el nuevo rango del componente: ";
            string rangoNuevo;
            getline(cin, rangoNuevo);
            analisis.editarComponente(posComponente, new Componente(nombreNuevo, valorNuevo, rangoNuevo));
            cout << "Componente editado correctamente." << endl;
        } else {
            cout << "Operación cancelada." << endl;
        }
    }
}

void eliminarAnalisis(Menu& menu) {
    int folio;
    system(CLEAR);
    cout << ">> Eliminar Analisis <<" << endl;
    cout << "Ingrese el folio del análisis a eliminar: ";
    cin >> folio;
    cin.ignore();
    int pos = buscarPorFolio(menu, folio);
    if (pos == -1) {
        cout << "No se encontró el análisis con el folio proporcionado." << endl;
        return;
    }else{
        system(CLEAR);
        cout << "Análisis encontrado: " << endl;
        cout <<mostrarPorFolio(menu, folio);
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
            auto& lista = menu.getListaAnalisis();
            lista.erase(lista.begin() + pos);
            cout << "\nAnálisis eliminado correctamente." << endl;

            }else{
                cout << "Operación cancelada." << endl;

            }
        }else if(opc == 2){
            cout << "Ingrese el nombre del componente a eliminar: ";
            string nombre;
            getline(cin, nombre);
            cout << nombre << endl;
            auto& analisis = *menu.getListaAnalisis()[pos];
            int pos = analisis.buscarComponentePorNombre(nombre);
            if(pos == -1){
                cout << "No se encontró el componente con el nombre proporcionado."<< endl;
                return;
            }
            cout << "Componente encontrado: " << endl;
            cout << analisis.mostrarComponente(pos);
            cout << "¿Está seguro de eliminar el componente? (s/n): ";
            char opc2;
            cin >> opc2;
            cin.ignore();
            if(opc2 == 's' || opc2 == 'S'){

                analisis.removeComponente(pos);
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

string mostrarAnalisis(const Menu& menu) {
    stringstream sout;
    for(auto& analisis : menu.getListaAnalisis()){
        sout << analisis->str() << endl;
    }
    return sout.str();
}

vector<unique_ptr<AnalisisBase>> copiarLista(const Menu& menu) {
    vector<unique_ptr<AnalisisBase>> copia;
    for (const auto& analisis : menu.getListaAnalisis()) {
        if(analisis->getTipo() == "EGO"){
            unique_ptr<EGO> ego = make_unique<EGO>();
            ego->setNombre(analisis->getNombre());
            ego->setFecha(analisis->getFecha());
            ego->setFolio(analisis->getFolio());
            for (const auto& componente : analisis->getComponentes()) {
                ego->addComponente(new Componente(componente));
            }
            copia.emplace_back(std::move(ego));
        } else if(analisis->getTipo() == "QS"){
            unique_ptr<QS> qs = make_unique<QS>();
            qs->setNombre(analisis->getNombre());
            qs->setFecha(analisis->getFecha());
            qs->setFolio(analisis->getFolio());
            for (const auto& componente : analisis->getComponentes()) {
                qs->addComponente(new Componente(componente));
            }
            copia.emplace_back(std::move(qs));
        } else if(analisis->getTipo() == "Cultivo"){
            unique_ptr<Cultivo> cultivo = make_unique<Cultivo>();
            cultivo->setNombre(analisis->getNombre());
            cultivo->setFecha(analisis->getFecha());
            cultivo->setFolio(analisis->getFolio());
            for (const auto& componente : analisis->getComponentes()) {
                cultivo->addComponente(new Componente(componente));
            }
            copia.emplace_back(std::move(cultivo));
        }
    }
    return copia;
}

string ordenarNombre(const Menu& menu) {
    stringstream sout;
    vector<unique_ptr<AnalisisBase>> analisisOrdenados = copiarLista(menu);
    sort(analisisOrdenados.begin(), analisisOrdenados.end(), [](const unique_ptr<AnalisisBase>& a, const unique_ptr<AnalisisBase>& b) {
        return a->getNombre() < b->getNombre();
    });
    for(auto& analisis : analisisOrdenados){
        sout << analisis->str() << endl;
    }
    return sout.str();
}

string ordenarFecha(const Menu& menu) {
    stringstream sout;
    vector<unique_ptr<AnalisisBase>> analisisOrdenados = copiarLista(menu);
    sort(analisisOrdenados.begin(), analisisOrdenados.end(), [](const unique_ptr<AnalisisBase>& a, const unique_ptr<AnalisisBase>& b) {
        return a->getFecha() < b->getFecha();
    });
    for(auto& analisis : analisisOrdenados){
        sout << analisis->str() << endl;
    }
    return sout.str();
}

string ordenarTipo(const Menu& menu) {
    stringstream sout;
    vector<unique_ptr<AnalisisBase>> analisisOrdenados = copiarLista(menu);
    sort(analisisOrdenados.begin(), analisisOrdenados.end(), [](const unique_ptr<AnalisisBase>& a, const unique_ptr<AnalisisBase>& b) {
        return a->getTipo() < b->getTipo();
    });
    for(auto& analisis : analisisOrdenados ){
        sout << analisis->str() << endl;
    }
    return sout.str();
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
        system(CLEAR);
        cout << "Analisis ordenados por nombre: " << endl;
        cout << ordenarNombre(menu);
        break;
    case 2:
        // Ordenar por fecha
        system(CLEAR);
        cout << "Analisis ordenados por fecha: " << endl;
        cout << ordenarFecha(menu);
        break;
    case 3:
        // Ordenar por tipo
        system(CLEAR);
        cout << "Analisis ordenados por tipo: " << endl;
        cout << ordenarTipo(menu);
        break;
    case 4:
        // Ordenar por folio
        system(CLEAR);
        cout << "Analisis ordenados por folio: " << endl;
        cout << mostrarAnalisis(menu);
        break;
    // Agregar aquí la lógica para ordenar los análisis
    }
    
}

void mostrarMenu() {
    cout << "=== Menú Principal ===" << setw(30)<< endl;
    cout << "1. Registrar análisis" << endl;
    cout << "2. Consultar análisis" << endl;
    cout << "3. Editar análisis" << endl;
    cout << "4. Eliminar análisis" << endl;
    cout << "5. Ordenar análisis" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}






























void a(Menu& menu) {
    
    vector<string> nombres = {"Juan Perez", "Maria Lopez", "Carlos Sanchez", "Ana Gomez", "Luis Fernandez"};
    vector<string> fechas = {"2023-10-01", "2023-10-02", "2023-10-03", "2023-10-04", "2023-10-05"};
    
    for (int i = 0; i < 5; ++i) {
        string nombre = nombres[i];
        string fecha = fechas[i];
        string tipo;
        
        if (i % 3 == 0) {
            tipo = "EGO";
            unique_ptr<EGO> ego = make_unique<EGO>();
            ego->setNombre(nombre);
            ego->setFecha(fecha);
            ego->setFolio(menu.getFolio());
            menu.incrementarFolio();
            ego->addComponente(new Componente("Glucosa", "90 mg/dL", "70-100 mg/dL"));
            ego->addComponente(new Componente("Proteínas", "Negativo", "Negativo"));
            menu.getListaAnalisis().emplace_back(std::move(ego));
        } else if (i % 3 == 1) {
            tipo = "QS";
            unique_ptr<QS> qs = make_unique<QS>();
            qs->setNombre(nombre);
            qs->setFecha(fecha);
            qs->setFolio(menu.getFolio());
            menu.incrementarFolio();
            qs->addComponente(new Componente("Colesterol", "180 mg/dL", "125-200 mg/dL"));
            qs->addComponente(new Componente("Triglicéridos", "150 mg/dL", "50-150 mg/dL"));
            menu.getListaAnalisis().emplace_back(std::move(qs));
        } else {
            tipo = "Cultivo";
            unique_ptr<Cultivo> cultivo = make_unique<Cultivo>();
            cultivo->setNombre(nombre);
            cultivo->setFecha(fecha);
            cultivo->setFolio(menu.getFolio());
            menu.incrementarFolio();
            cultivo->addComponente(new Componente("Bacterias", "Positivo", "Negativo"));
            cultivo->addComponente(new Componente("Leucocitos", "10 /µL", "0-5 /µL"));
            menu.getListaAnalisis().emplace_back(std::move(cultivo));
        }
    }
}