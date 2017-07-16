CC=gcc
CXX=g++
RM=rm -f
PR=lager
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=main.cpp Aufgabe.cpp Aufgabe.h Produkt.cpp Produkt.h Projekt.cpp Projekt.h Projektbestandteil.cpp Projektbestandteil.h Test.cpp Test.h
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: Projekt
Projekt: main.o Aufgabe.o Produkt.o Projekt.o Projektbestandteil.o Test.o
	$(CXX) $(CPPFLAGS) -o projekt main.o Aufgabe.o Produkt.o Projekt.o Projektbestandteil.o Test.o
main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp
Aufgabe.o: Aufgabe.cpp 
	$(CXX) $(CPPFLAGS) -c Aufgabe.cpp 
Produkt.o: Produkt.cpp 
	$(CXX) $(CPPFLAGS) -c Produkt.cpp 
Projekt.o: Projekt.cpp 
	$(CXX) $(CPPFLAGS) -c Projekt.cpp 
Projektbestandteil.o: Projektbestandteil.cpp 
	$(CXX) $(CPPFLAGS) -c Projektbestandteil.cpp
Test.o: Test.cpp
	$(CXX) $(CPPFLAGS) -c Test.cpp
	
.PHONY: clean
clean:
	$(RM) $(PR) *.o *.gch

.PHONY: clear
clear:
	$(RM) *.o *.gch
