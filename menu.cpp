#include "menu.h"
#include "Cultivo.h"

#include <iostream>
using namespace std;
#ifdef _WIN32
#define CLEAR "cls"  // Comando para limpiar pantalla en Windows
#else
#define CLEAR "clear"  // Comando para limpiar pantalla en otros SO
#endif
void registroCultivo();
void mostrarMenu();

Menu::Menu(){
    folioGlobal = 1;
    bool seguir = true;
    int opc;
    //main

    do
    {
        system(CLEAR); //Borra toda la pantalla
        mostrarMenu();
        cin >> opc;

        switch (opc){
        case 1:
            /* code */
            break;
        
        default:
            break;
        }

    } while (seguir);
    

}
int Menu::getFolio(){
    return folioGlobal;
}
void Menu::incrementarFolio(){

    folioGlobal++;
}
void Menu::setFolio(int folio){
    folioGlobal = folio;
}

void registroCultivo(){
    Cultivo cultivo;
    string nombre;

    cout << "Dame tu nombre:";
    getline(cin, nombre);

}
void mostrarMenu(){
    
}