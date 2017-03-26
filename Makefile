# Makefile for the finalclass class

runfinalclass: final.o finalclass.o
	g++ -lX11 final.o finalclass.o gfxnew.o -o runfinalclass

final.o: final.cpp finalclass.h
	g++ -lX11 -c final.cpp

finalclass.o: finalclass.cpp finalclass.h gfxnew.h
	g++ -lX11 -c finalclass.cpp

clean:
	rm runfinalclass.o 
	rm final.o 
	rm finalclass.o

