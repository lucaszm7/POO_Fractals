#include "Fractal.h"
#include <iostream>
using namespace std;

void Fractal::setReal(double maxR, double minR)
{
    this->maxReal = maxR;
    this->minReal = minR;
}

void Fractal::setImaginary(double maxI, double minI)
{
    this->maxImag = maxI;
    this->minImag = minI;
}

double Fractal::getReal(int x, int img)
{
    double range;

    range = this->maxReal - this->minReal;

    return x * (range / img) + this->minReal;
}

double Fractal::getImaginary(int y, int img)
{
    double range;

    range = this->maxImag - this->minImag;

    return y * (range / img) + this->minImag;
}
