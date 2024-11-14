#ifndef MENU
#define MENU
#include <vector>
#include <memory>

#include "AnalisisBase.h"
class Menu
{
    private:
        int folioGlobal;
        vector<std::unique_ptr<AnalisisBase>> listaAnalisis;
    public:
        Menu();
        int getFolio();
        void setFolio(int folio);
        void incrementarFolio();
        const vector<std::unique_ptr<AnalisisBase>>& getListaAnalisis() const;
        vector<std::unique_ptr<AnalisisBase>>& getListaAnalisis();

    protected:

};

#endif // MENU