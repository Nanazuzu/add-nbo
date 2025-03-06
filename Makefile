#Makefile
all: add-nbo

add-nbo: source.o
	g++ -o add-nbo source.o

source.o: phc.h
	g++ -c -o source.o source.cpp

clean:
	rm -f add-nbo
	rm -f *.o
	rm -f *.bin
