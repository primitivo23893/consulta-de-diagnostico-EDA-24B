#ifndef ANALISISBASE_H
#define ANALISISBASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class AnalisisBase {
public:
    virtual ~AnalisisBase() {}
    virtual string str() const = 0;
    virtual void guardarEnArchivo(ofstream& archivo) const = 0;
};

#endif // ANALISISBASE_H