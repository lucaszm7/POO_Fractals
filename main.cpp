#include <fstream>
#include <iostream>
#include "Fractal.h"
#include "Julia.h"
#include "Mandelbrot.h"

int menu() {
    int esc;
    cout << "FRACTALS:\n1 - Mandelbroth\n2 - Julia\n3 - Sair" << endl;
    cin >> esc;
    return esc;

}

using namespace std;

int main()
{
    int imageHeight = 4096, imageWidth = 4096;
    int x, y;
    int r, g, b;
    int maxN = 1024;
    int n;
    double rx, ry;

    ofstream fileMand("mandelbrot.ppm");
    ofstream fileJu("juliaset.ppm");

    fileMand << "P3" << endl
             << imageWidth << " " << imageHeight << endl
             << "256" << endl;
    fileJu << "P3" << endl
           << imageWidth << " " << imageHeight << endl
           << "256" << endl;

    Mandelbrot * mand;
    Julia * ju;

    mand = new Mandelbrot;
    ju = new Julia;


    mand->setReal(0.7, -1.5);
    mand->setImaginary(1.0, -1.0);

    ju->setReal(1.7, -1.7);
    ju->setImaginary(1.7, -1.7);

    int esc = 0;

    while (esc != 3) {
        esc = menu();
        if (esc == 1) {
            for(y = 0; y < imageHeight; ++y)
            {
                for(x = 0; x < imageWidth; ++x)
                {
                    rx = mand->getReal(x, imageWidth);
                    ry = mand->getImaginary(y, imageHeight);

                    n = mand->findMandelbrot(rx, ry, maxN);

                    r = ((n % 255)* 25);
                    g = ((n % 255)* 10);
                    b = ((n % 255)* 25);

                    fileMand << r << " " << g << " " << b << " ";
                }
                fileMand << endl;
            }
            fileMand.close();
            cout << "Arquivo Gerado!!" << endl;
            system("mandelbrot.ppm");
        }

        if (esc == 2) {
            double jr,ji;
            cout << "Cr = "; cin >> jr;
            ju->setCr(jr);
            cout << "Ci = "; cin >> ji;
            ju->setCi(ji);
            for(y = 0; y < imageHeight; ++y)
            {
                for(x = 0; x < imageWidth; ++x)
                {
                    rx = ju->getReal(x, imageWidth);
                    ry = ju->getImaginary(y, imageHeight);

                    n = ju->findJulia(rx, ry, maxN);

                    r = (n % 255);
                    g = (n % 255);
                    b = (n % 255);

                    fileJu << r << " " << g << " " << b << " ";
                }
                fileJu << endl;
            }
            fileJu.close();
            cout << "Arquivo Gerado!!" << endl;
            system("juliaset.ppm");
        }
    }

    cout << "Saindo do Programa!!" << endl;

    return 0;
}
