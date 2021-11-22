#include "Mandelbrot.h"
#include <iostream>
using namespace std;

int Mandelbrot::findMandelbrot(double cr, double ci, int maxN)
{
    int i=0;
    double zr=0.0, zi=0.0, rtemp;

    while((i < maxN) && (((zr*zr) + (zi*zi)) < 4.0))
    {
        rtemp = (zr * zr) - (zi * zi) + cr;
        zi = 2.0 * (zr * zi) + ci;
        zr = rtemp;

        i++;
    }
    return i;
}
