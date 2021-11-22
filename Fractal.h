#ifndef FRACTAL_H
#define FRACTAL_H

class Fractal
{
protected:
    double maxReal, minReal;
    double maxImag, minImag;
    int maxIterations;
public:
    Fractal()
        : maxReal(0.0), minReal(0.0),
          maxImag(0.0), minImag(0.0),
          maxIterations(0) { }

    Fractal(const Fractal&) = default;
    void setReal(double maxN, double minN);
    void setImaginary(double maxN, double minN);
    double getReal(int r, int img);
    double getImaginary(int i, int img);
    ~Fractal();
};

#endif
