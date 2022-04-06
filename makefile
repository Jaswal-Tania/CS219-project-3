all: project

project: main.o hexRead.o
	g++ -o project main.o hexRead.o

main.o: main.cpp
	g++ -c main.cpp

hexRead.o: hexRead.cpp hexRead.h
	g++ -c hexRead.cpp

clean:
	rm *.o project