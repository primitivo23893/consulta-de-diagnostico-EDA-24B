#ifndef QS_H
#define QS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "AnalisisBase.h"
#include "Componente.h"

using namespace std;

class QS : public AnalisisBase {
    private:

    public:
        QS();
        string getTipo() const override;

};

#endif // QS_H