CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all: Test Test2

Test: ladder_main.o ladder.o
	g++  $(CXXFLAGS)  ladder_main.o ladder.o -o Test
src/ladder.o: ladder.cpp
	g++  $(CXXFLAGS)  ladder.cpp   -c   ladder
src/ladder_main.o: ladder_main.cpp
	g++  $(CXXFLAGS)  ladder_main.cpp   -c   ladder_main

Test2: dijkstras_main.o dijkstras.o
	g++  $(CXXFLAGS)  dijkstras_main.o dijkstras.o -o Test2
src/dijkstras.o: dijkstras.cpp
	g++  $(CXXFLAGS)  dijkstras.cpp   -c   dijkstras
src/dijkstras_main.o: dijkstras_main.cpp
	g++  $(CXXFLAGS)  dijkstras_main.cpp   -c   dijkstras_main


clean:
	rm ladder_main.o ladder.o Test dijkstras_main.o dijkstras.o Test2