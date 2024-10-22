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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <chrono>
#include <sstream>
#include <iterator>
#include <map>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <mpi.h>


#include <sys/time.h>
extern "C" void vipra_(int &, int&, double&, double&, double&, double&, double&);

double    microtime(void)
{
  struct timeval t;

  gettimeofday(&t, 0);

  return 1.0e6*t.tv_sec + (double) t.tv_usec;
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

void master(char *);
void slave();
//void CALM(Numeric sm, Numeric idt, Numeric isc, Numeric asc, Numeric tasc, Numeric rt, int ID);
void SPED(float params[6]);

using namespace std;

int id;    // process rank
int np;    // number of MPI processes
int NUM = 8000;   // number of tasks to be processed  (given 
char filename[32] = "sequences.txt";
int main ( int argc, char **argv );
void timestamp ( );




void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss;
  ss.str(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}



//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
{
  double wtime;
  clock_t begin = clock();
  MPI_Init (&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &np);

  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  
  // printf("Timer resolution = %g micro seconds\n", get_microtime_resolution());

  double time1 = microtime();

  //NUM= atoi(argv[1]);
  if(id==0){
    cout<<"NP: "<<np<<endl;
    cout<<"Num: "<<NUM<<endl;
  
  timestamp ( );
  }
       wtime = MPI_Wtime ( );

       if (id == 0) {
                master(filename);
        } else {
                slave();
        }

        wtime = MPI_Wtime ( ) - wtime;
	//	printf ( "  Process %d time = %g\n", id, wtime );


    MPI_Finalize ( );
    //cout<<"\n";
    //cout<<"  Normal end of execution.\n";
    if(id==0){
      clock_t end = clock();
      double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
      cout<<"Elapsed Time: "<<elapsed_secs <<"(s)"<<endl;
      timestamp ( );
      double time2 = microtime();

      printf("Time taken = %g seconds\n", (time2-time1)/1.0e6);
    }
  return 0;
}



void master(char *filename)
{
  int     rank;
	float result[7];
	MPI_Status     status;
	
        ifstream aFile (filename);       
        
/*
* Seed the slaves.
*/      //int nextp=0;
        string line;
	int p=0;
        for (rank = 1; rank < np; ++rank) {
                getline (aFile, line);
                vector<string> params;
		//MPI_Request req;
		split(line, ' ', params);
		float parameters[6]; /*master will send the ID of next simulation along with six parameters in an array*/
		parameters[0] = p;
		//cout<<params.size()<<endl;
		for(int i=1; i<6; ++i){
		  //cout<<"i is "<<i<<endl;
		  parameters[i] = atof(params[i-1].c_str());
		}
                //work = nextp;      ; /* get_next_work_request */
		 MPI_Send(parameters,         /* message buffer */
                6,              /* one data item */
                MPI_FLOAT,        /* data item is an integer */
                rank,           /* destination process rank */
			  1,
			  MPI_COMM_WORLD);       /* user chosen message tag */
		 p++;
        }

/*
* Receive a result from any slave and dispatch a new work
* request work requests have been exhausted.
*/
        //while ( nextp < NUM)/* valid new work request */ 
        while ( p< NUM)
        {
                std::getline (aFile, line);
                vector<string> params;
                split(line, ' ', params);
                float parameters[6]; /*master will send the ID of next simulation along wi\
				       th six parameters in an array*/
                parameters[0] = p;
                for(int i=1; i<6; ++i){
                  parameters[i] = atof(params[i-1].c_str());
                }
                MPI_Recv(&result,       /* message buffer */
                1,              /* one data item */
                MPI_INT,     /* of type double real */
                MPI_ANY_SOURCE, /* receive from any sender */
                MPI_ANY_TAG,    /* any type of message */
		MPI_COMM_WORLD,
                &status);       /* received message info */
		//MPI_Request req;
		MPI_Send(parameters, 6, MPI_FLOAT, status.MPI_SOURCE,
			 1, MPI_COMM_WORLD);
		p++;

        }
/*
* Receive results for outstanding work requests.
*/
        for (rank = 1; rank < np; ++rank) {
	  MPI_Recv(&result, 6, MPI_FLOAT, MPI_ANY_SOURCE,
		   MPI_ANY_TAG, MPI_COMM_WORLD, &status);
          float fake_parameters[6];
	  
	  for(int i=0; i<6; ++i){
	    fake_parameters[i] = -1;
	  }
	  MPI_Send(fake_parameters, 6, MPI_FLOAT, status.MPI_SOURCE, 2, MPI_COMM_WORLD);
        }
/*
* Tell all the slaves to exit.  .. This is inefficient - the above recv statement is like a barrier -- need not wait for all recvs
*/
/*
        for (rank = 1; rank < np; ++rank) {
                 MPI::COMM_WORLD.Send(0, 0, MPI::INT, rank, DIETAG);
  	}
*/
}



void slave()
{
        int              result;
        float                 work[6];
	MPI_Status          status;
        //char                buffer[200];
        for (;;) {
	  MPI_Recv(&work, 6, MPI_FLOAT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
/*
* Check the tag of the received message.
*/
	  // MPI_Request req;
                if (status.MPI_TAG == 2) {
                        return;
                }
		//sprintf(buffer,"%d %d\n", work, np);
		//system(buffer);
		SPED(work);
		//vipra(work[0], np, work[1], work[2], work[3], work[4], work[5]);
		result = 1; /* do the work */ 
		// result is redundant - serves no real purpose than to indicate job is done
                
                MPI_Send(&result, 1, MPI::INT, 0, 0, MPI_COMM_WORLD);
        }
}


//*****************************************************************************

void SPED(float params[6]){
  double time1 = microtime();
  double min_SCB = 14.7f;
  double min_Sig = 26.0f;
  double min_Eps = 0.15f;
  double min_SCA = 3.0f;
  double min_Tlug = 7.0f;
  

  double max_SCB = 15.8f;
  double max_Sig = 31.0f;
  double max_Eps = 1.9f;
  double max_SCA = 8.0f;
  double max_Tlug = 12.0f;
  
  
  double this_SCB = (max_SCB - min_SCB) *  params[1] +  min_SCB;
  double this_Sig = (max_Sig - min_Sig) * params[2] + min_Sig;
  double this_Eps = (max_Eps - min_Eps) * params[3] + min_Eps;
  double this_SCA = (max_SCA - min_SCA) * params[4] + min_SCA;
  double this_Tlug = (max_Tlug - min_Tlug) * params[5] + min_Tlug;
  this_Eps *= 100000;
  int ID = (int)params[0];

  ofstream output;
  char ofile[128];
  sprintf(ofile, "output%d", ID);
  output.open(ofile);

  output<<"Running simulation with SimID= "<<params[0]<<", SCB= "<<this_SCB<<", Sig= "<<this_Sig<<", Eps= "<<this_Eps<<", SCA= "<<this_SCA<<", Tlug= "<<this_Tlug<<endl;
  vipra_(ID, np, this_SCB, this_Sig, this_Eps, this_SCA, this_Tlug);
  
  double time2=microtime();

  output<<"Run-Time: "<<(time2-time1)/1.0e6 <<" seconds\n";
  output.close();
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
