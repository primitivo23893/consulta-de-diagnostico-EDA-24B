#ifndef EGO_H
#define EGO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "AnalisisBase.h"
#include "Componente.h"

using namespace std;

class EGO : public AnalisisBase {
    private:

    public:
        EGO();
        string getTipo() const override;

};

#endif // EGO_H
