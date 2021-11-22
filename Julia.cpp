#include "Julia.h"

using namespace std;

int Julia::findJulia(double zr, double zi,int maxN)
{
    int i=0;
    double rtemp;
    while((i < maxN) && (((zr*zr) + (zi*zi)) < 4.0))
    {
        rtemp = (zr * zr) - (zi * zi);
        zi = 2.0 * (zr * zi) + this->ci;
        zr = rtemp + this->cr;

        i++;
    }

    return i;
}
