all: maze.o robot.o
	g++ maze.o robot.o main.cpp -std=c++17 -o main

maze.o: maze.cpp maze.h
	g++ -c maze.cpp

robot.o: robot.cpp robot.h
	g++ -c robot.cpp
