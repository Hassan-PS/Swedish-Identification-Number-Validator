main: Identifier.o Personnummer.o Samordningsnummer.o Organisationsnummer.o main.o
	g++ main.o Identifier.o Personnummer.o Samordningsnummer.o Organisationsnummer.o -o main

main.o: main.cpp
	g++ -c -std=c++17 main.cpp

Identifier.o: Identifier.cpp
	g++ -c -std=c++17 Identifier.cpp

Personnummer.o: Personnummer.cpp
	g++ -c -std=c++17 Personnummer.cpp

Samordningsnummer.o: Samordningsnummer.cpp
	g++ -c -std=c++17 Samordningsnummer.cpp

Organisationsnummer.o: Organisationsnummer.cpp
	g++ -c -std=c++17 Organisationsnummer.cpp

debug:
	g++ -std=c++17 -g main.cpp main.h Identifier.cpp Identifier.h Personnummer.cpp Personnummer.h Samordningsnummer.cpp Samordningsnummer.h Organisationsnummer.cpp Organisationsnummer.h

clear:
	clear
	rm *.pkgf *.o *.out main *.h.gch

