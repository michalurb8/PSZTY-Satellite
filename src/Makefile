CF = -Wall -pedantic -std=c++11 -O3
LF = -lallegro -lallegro_primitives

default: main.o Universe.o Planet.o DrawingClass.o
	g++ main.o Universe.o Planet.o DrawingClass.o -o exe $(LF) 

main.o: main.cpp 
	g++ $(CF) -c main.cpp -o main.o

Universe.o: Universe.cpp 
	g++ $(CF) -c Universe.cpp -o Universe.o

Planet.o: Planet.cpp 
	g++ $(CF) -c Planet.cpp -o Planet.o

DrawingClass.o: DrawingClass.cpp 
	g++ $(CF) -c DrawingClass.cpp -o DrawingClass.o

clean:
	rm -f *.o exe

run: default
	./exe