MPICC=mpicxx
CCCFLAGS=-std=c++11 -O3 -lifcore

SPED: DynamicLB.o main.o
	$(MPICC) $(CCCFLAGS) -o SPED DynamicLB.o main.o

DynamicLB.o: DynamicLB.cpp
	$(MPICC) $(CCCFLAGS) -c DynamicLB.cpp 
main.o: main.f
	mpiifort -fast main.f -c -o main.o
clean:
	rm -f *.o SPED *~ animfile.xyz

