#ifndef MANDELBROT_H
#define MANDELBROT_H
#include "Fractal.h"

using namespace std;

class Mandelbrot : public Fractal {
public:
    int findMandelbrot(double cr, double ci, int maxN);
};

#endif
