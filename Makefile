GPP = g++

all: Fractal.o Mandelbrot.o Julia.o main.o
	$(GPP) Fractal.o Mandelbrot.o Julia.o main.o -o exec

Fractal.o: Fractal.cpp
	$(GPP) -c Fractal.cpp

Mandelbrot.o: Mandelbrot.cpp
	$(GPP) -c Mandelbrot.cpp

Julia.o: Julia.cpp
	$(GPP) -c Julia.cpp

main.o: main.cpp
	$(GPP) -c main.cpp

clean:
	rm -f *.o
