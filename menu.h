#ifndef MENU
#define MENU

#include "AnalisisBase.h"
class Menu
{
    private:
        int folioGlobal;
        AnalisisBase analisisBase;
    public:
        Menu();
        int getFolio();
        void setFolio(int folio);
        void incrementarFolio();
        AnalisisBase getAnalisisBase();
    protected:

};

#endif // MENU