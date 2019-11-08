CF = -Wall -pedantic -std=c++11 -O3
LF = -lallegro 

default: main.o Universe.o
	g++ $(LF) main.o Universe.o -o exe

main.o: main.cpp 
	g++ $(CF) -c main.cpp -o main.o

Universe.o: Universe.cpp 
	g++ $(CF) -c Universe.cpp -o Universe.o

clean:
	rm -f *.o exe

run: default
	./exe