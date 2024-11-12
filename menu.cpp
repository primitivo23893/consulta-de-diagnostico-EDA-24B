#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
    folioGlobal = 1;
    //main



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