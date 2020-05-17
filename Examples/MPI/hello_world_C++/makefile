EXECS=mpi_hello_world
MPICC?=mpicxx

all: ${EXECS}

mpi_hello_world: mpi_hello_world.cpp
		${MPICC} -o mpi_hello_world mpi_hello_world.cpp

clean:
		rm ${EXECS}
