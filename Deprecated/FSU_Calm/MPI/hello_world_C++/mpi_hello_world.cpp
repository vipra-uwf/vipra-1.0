#include "mpi.h"
#include <iostream>
#include <string>

/*
argc - argument count
argv - argument vector
*/
int main(int argc, char *argv[])
{
    int number_of_processes;
    int process_id;
    char message[128];
    MPI_Status status;

    //initialize the MPI system (must be the first MPI function)
    MPI_Init(&argc, &argv);

    //getting number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &number_of_processes);

    //getting process id/rank
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

    //Master
    if(process_id == 0)
    {
        for(int i = 1; i < number_of_processes; ++i)
        {
            sprintf(message, "Master says, \"Hello, Slave %d\"", i);
            std::cout << message << std::endl;

            MPI_Send(message, 128, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }

        for(int i = 1; i < number_of_processes; ++i)
        {
            MPI_Recv(message, 128, MPI_CHAR, i, 0, MPI_COMM_WORLD, &status);
            std::cout << "Master hears " << message << std::endl;
        }
    }
    //Slave
    else
    {
        MPI_Recv(message, 128, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        std::cout << "Slave " << process_id << " hears " << message << std::endl;

        sprintf(message, "Slave %d say, \"Hello, Master\"", process_id);
        MPI_Send(message, 128, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    //terminates the MPI system
    MPI_Finalize();
}

/*
Every MPI function returns an integer ERROR CODE
if an MPI function is successful (no error),
it will return MPI code MPI_SUCCESS

Processes in MPI are divided into Communicator Groups,
(a list/group of MPI processes that can communicate with one another)
The default Communicator Group is 'MPI_COMM_WORLD'


Compilation and Execution Instructions:
make
mpirun -np 4 mpi_hello_world
*/
