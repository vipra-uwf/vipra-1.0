CCC=g++
MPICC=mpicxx
CCCFLAGS=-std=c++11 -O3


calm: main.o Simulation.o
	$(MPICC) $(CCCFLAGS) -o calm main.o Simulation.o

main.o: main.cpp
	$(MPICC) $(CCCFLAGS) -c main.cpp


Simulation.o: Simulation.cpp
	$(CCC) $(CCCFLAGS) -c Simulation.cpp
clean:
	rm -f *.o calm *~ animfile.xyz debug.txt
