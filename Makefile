#Makefile
all: add-nbo

add-nbo: source.o file_hand.o byte_orde.o
	g++ -o add-nbo source.o file_hand.o byte_orde.o

source.o: phc.h source.cpp
	g++ -c -o source.o source.cpp

file_hand.o: phc.h file_hand.cpp
	g++ -c -o file_hand.o file_hand.cpp

byte_orde.o: phc.h byte_orde.cpp
	g++ -c -o byte_orde.o byte_orde.cpp

clean:
	rm -f add-nbo
	rm -f *.o
	rm -f *.bin
