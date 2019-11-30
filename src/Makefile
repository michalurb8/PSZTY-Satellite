CF = -Wall -pedantic -std=c++11 -O3
LF = -lallegro -lallegro_primitives

default: main.o Universe.o Planet.o DrawingClass.o Rocket.o FlightControl.o
	g++ main.o Universe.o Planet.o DrawingClass.o Rocket.o FlightControl.o -o exe $(LF) 

main.o: main.cpp
	g++ $(CF) -c main.cpp -o main.o

Universe.o: Universe.cpp Universe.h
	g++ $(CF) -c Universe.cpp -o Universe.o

Planet.o: Planet.cpp Planet.h
	g++ $(CF) -c Planet.cpp -o Planet.o

DrawingClass.o: DrawingClass.cpp DrawingClass.h
	g++ $(CF) -c DrawingClass.cpp -o DrawingClass.o

Rocket.o: Rocket.cpp Rocket.h
	g++ $(CF) -c Rocket.cpp -o Rocket.o

FlightControl.o: FlightControl.cpp FlightControl.h
	g++ $(CF) -c FlightControl.cpp -o FlightControl.o

clean:
	rm -f *.o exe

run: default
	./exe

reset: clean default