#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    folioGlobal = 1;
    //main
    cout << "Hola mundo!!" << endl;

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