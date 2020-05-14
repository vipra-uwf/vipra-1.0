CCC=g++
CCCFLAGS=-std=c++11 -g -Wall -O3


SPED: main.o Simulation.o Plane.o
	$(CCC) $(CCCFLAGS) -o SPED main.o Simulation.o Plane.o

main.o: main.cpp
	$(CCC) $(CCCFLAGS) -c main.cpp
Plane.o: Plane.cpp
	$(CCC) $(CCCFLAGS) -c Plane.cpp

Simulation.o: Simulation.cpp
	$(CCC) $(CCCFLAGS) -c Simulation.cpp
clean:
	rm -f *.o SPED *~ animfile.xyz debug.txt
