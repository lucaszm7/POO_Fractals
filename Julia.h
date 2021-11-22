#ifndef JULIA_H
#define JULIA_H
#include "Fractal.h"

using namespace std;

class Julia : public Fractal
{
public:
    int findJulia(double cr, double ci, int maxN);
    void setCr(double cr) {
        this->cr = cr;
    }
    void setCi(double ci) {
        this->ci = ci;
    }
private:
    double cr;
    double ci;
};

#endif
