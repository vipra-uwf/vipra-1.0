/*
**************************************************************************
In principle, this file is same as movement.cpp, however, it is based on dynamic load
balancing with a next available core getting the next task.
Core 0 (Rank 0) acts as the master co-ordinating the work distribution

USAGE: takes two arguments (the number of parameter combinations)
mpirun -n 100 ./movement_lb1 1331 file
****(file - tasks id) - one column of tasks id ( to generate this file, order the tasks based on the time)
This file is NOT  the output of BalanceLoad !!!
**************************************************************************/


# include <cstdlib>
# include <iostream>
# include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <sys/time.h>

extern "C" void vipra_(int &, int&, double&, double&, double&, double&, double&);

#define WORKTAG     1
#define DIETAG     2
using namespace std;
#include "mpi.h"

void master(char *, char*);
void slave();



using namespace std;

int id;    // process rank
int np;    // number of MPI processes
int NUM;   // number of tasks to be processed  (given 
double time1, time2;


int main ( int argc, char *argv[] );
void timestamp ( );
double    microtime(void); /* Time in micro-seconds */
double    get_microtime_resolution(void); /* Timer resolution in micro-seconds */

//SCB,sigt1,epst1,SCA, tlug

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
{
  double wtime;
  char buffer[200];

  MPI::Init ( argc, argv );

  id = MPI::COMM_WORLD.Get_rank ( );

  np = MPI::COMM_WORLD.Get_size ( );

  NUM= atoi(argv[1]);

	
       timestamp ( );
       wtime = MPI::Wtime ( );


       if (id == 0) {
                time1 = microtime();
                master(argv[2], argv[3]);
                time2 = microtime();
                printf("Time taken by process master = %g seconds\n", (time2-time1)/1.0e6);
        } else {
                slave();
        }

        wtime = MPI::Wtime ( ) - wtime;

	printf ( "  Process %d time = %g\n", id, wtime );


    MPI::Finalize ( );
    printf ( "\n" );
    printf ( "  Normal end of execution.\n" );

    timestamp ( );
  return 0;
}

double    get_microtime_resolution(void)
{
  double time1, time2;

  time1 = microtime();
  do
  {
    time2 = microtime();
  } while(time1==time2);

  return time2-time1;
}



double    microtime(void)
{
  struct timeval t;

  gettimeofday(&t, 0);

  return 1.0e6*t.tv_sec + (double) t.tv_usec;
}


void master(char *inputfile, char* paramfile)
{
        int     rank, work;
        double       result;
	MPI::Status     status;

        ifstream iFile (inputfile);       
        ifstream pFile (paramfile);       
        
/*
* Seed the slaves.
*/      int nextp=0;
        double SCB=0,sigt1=0,epst1=0,SCA=0,tlug=0;
        std::string iline;
        std::string pline;
        double temp;
	int p=0;
        for (rank = 1; rank < np; ++rank) {
                std::getline (iFile, iline);
                std::getline (pFile, pline);
                nextp = std::atoi(iline.c_str());
                std::istringstream in(pline);
                /*temp = std::atof(pline.c_str());
                SCB = std::atof(pline.c_str());
                sigt1 = std::atof(pline.c_str());
                epst1 = std::atof(pline.c_str());
                SCA = std::atof(pline.c_str());
                tlug = std::atof(pline.c_str());*/
                in >> temp >> SCB >> sigt1 >> epst1 >> SCA >> tlug; 
		epst1 *= 100000;
		//printf("SCB: %lf sigt1:%lf epst1:%lf SCA:%lf tlug:%lf\n", SCB, sigt1, epst1, SCA, tlug);
                work = nextp;      ; /* get_next_work_request */
		 MPI::COMM_WORLD.Send(&work,         /* message buffer */
                1,              /* one data item */
                MPI::INT,        /* data item is an integer */
                rank,           /* destination process rank */
                WORKTAG);       /* user chosen message tag */
		MPI::COMM_WORLD.Send(&SCB, 1, MPI::DOUBLE, rank,WORKTAG );
		MPI::COMM_WORLD.Send(&sigt1, 1, MPI::DOUBLE, rank,WORKTAG );
		MPI::COMM_WORLD.Send(&epst1, 1, MPI::DOUBLE, rank,WORKTAG );
		MPI::COMM_WORLD.Send(&SCA, 1, MPI::DOUBLE, rank,WORKTAG );
		MPI::COMM_WORLD.Send(&tlug, 1, MPI::DOUBLE, rank,WORKTAG );
		 p++;
        }

/*
* Receive a result from any slave and dispatch a new work
* request work requests have been exhausted.
*/
        //while ( nextp < NUM)/* valid new work request */ 
        while ( p< NUM)
        {
                std::getline (iFile, iline);
                std::getline (pFile, pline);
                nextp = std::atoi(iline.c_str());
                std::istringstream in(pline);
                /*temp = std::atof(pline.c_str());
                SCB = std::atof(pline.c_str());
                sigt1 = std::atof(pline.c_str());
                epst1 = std::atof(pline.c_str());
                SCA = std::atof(pline.c_str());
                tlug = std::atof(pline.c_str()); */
                in >> temp >> SCB >> sigt1 >> epst1 >> SCA >> tlug; 
		epst1 *= 100000;
		//printf("SCB: %lf sigt1:%lf epst1:%lf SCA:%lf tlug:%lf\n", SCB, sigt1, epst1, SCA, tlug);
                work = nextp;/* get_next_work_request */
                MPI::COMM_WORLD.Recv(&result,       /* message buffer */
                1,              /* one data item */
                MPI::DOUBLE,     /* of type double real */
                MPI::ANY_SOURCE, /* receive from any sender */
                MPI::ANY_TAG,    /* any type of message */
                status);       /* received message info */

                MPI::COMM_WORLD.Send(&work, 1, MPI::INT, status.Get_source(),
                WORKTAG);
		MPI::COMM_WORLD.Send(&SCB, 1, MPI::DOUBLE, status.Get_source(),WORKTAG );
		MPI::COMM_WORLD.Send(&sigt1, 1, MPI::DOUBLE, status.Get_source(),WORKTAG );
		MPI::COMM_WORLD.Send(&epst1, 1, MPI::DOUBLE, status.Get_source(),WORKTAG );
		MPI::COMM_WORLD.Send(&SCA, 1, MPI::DOUBLE, status.Get_source(),WORKTAG );
		MPI::COMM_WORLD.Send(&tlug, 1, MPI::DOUBLE, status.Get_source(),WORKTAG );
		p++;

        }
/*
* Receive results for outstanding work requests.
*/
        for (rank = 1; rank < np; ++rank) {
                 MPI::COMM_WORLD.Recv(&result, 1, MPI::DOUBLE, MPI::ANY_SOURCE,
                MPI::ANY_TAG, status);
                 MPI::COMM_WORLD.Send(0, 0, MPI::INT, status.Get_source(), DIETAG);
        }
/*
* Tell all the slaves to exit.
*/
/*
        for (rank = 1; rank < np; ++rank) {
                 MPI::COMM_WORLD.Send(0, 0, MPI::INT, rank, DIETAG);
  	}
*/
}



void slave()
{
        double              result;
        int                 work;
	MPI::Status          status;
        char                buffer[200];
        double SCB=0,sigt1=0,epst1=0,SCA=0,tlug=0;
        for (;;) {
                 MPI::COMM_WORLD.Recv(&work, 1, MPI::INT, 0, MPI::ANY_TAG, status);
/*
* Check the tag of the received message.
*/
                if (status.Get_tag() == DIETAG) {
                        return;
                }
                 MPI::COMM_WORLD.Recv(&SCB, 1, MPI::DOUBLE, 0, MPI::ANY_TAG, status);
                 MPI::COMM_WORLD.Recv(&sigt1, 1, MPI::DOUBLE, 0, MPI::ANY_TAG, status);
                 MPI::COMM_WORLD.Recv(&epst1, 1, MPI::DOUBLE, 0, MPI::ANY_TAG, status);
                 MPI::COMM_WORLD.Recv(&SCA, 1, MPI::DOUBLE, 0, MPI::ANY_TAG, status);
                 MPI::COMM_WORLD.Recv(&tlug, 1, MPI::DOUBLE, 0, MPI::ANY_TAG, status);
		//sprintf(buffer,"%d %d\n", work, np);
		//system(buffer);
		//printf("SCB: %lf sigt1:%lf epst1:%lf SCA:%lf tlug:%lf\n", SCB, sigt1, epst1, SCA, tlug);
		vipra_(work, np, SCB, sigt1, epst1, SCA, tlug);
                result = 1; /* do the work */ 
		// result is redundant - serves no real purpose than to indicate job is done
                
                MPI::COMM_WORLD.Send(&result, 1, MPI::DOUBLE, 0, 0);
        }
}








//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  size_t len;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
