/**
 * The main fucntion is here. With a few changes this main function can be used for running several simulations in parallel using MPI.
 * @author  Mehran Sadeghi Lahijani <sadeghil@cs.fsu.edu>
 */

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


#include "Simulation.h"

using namespace std;

/**
 * converting an integer to string
 * @param i the integer to be converted to string
 **/
string int2str(int i)
{
  stringstream ss;
  ss << i;
  return ss.str();
}

/**
 * The main function will run a simulation then it will check to see if the simulation were terminated successfully.
 * If the simulation was not terminated successfully, it will run the same simulation again.
 *
 * @param cell The cell in which we need to search for the nearest passenger
 * @param passenger_t reference to the passenger that we are going to find the nearest passenger to him/her
 * @param nearest_t reference to the NearestPassenger object to modify if a closer passenger is found
 *
 **/
int main(int argc, char ** argv)
{
  int Rank=0;
  int SimID=Rank;

  ofstream output;
  char ofile[128];
  sprintf(ofile, "output%d", Rank);
  output.open(ofile);
  Simulation sim = Simulation(1.15f, 0.2f, 0.3f, 0.3f, 0.5f, 0.3f, 0.5f);
  int status = sim.Run(output);

  return 0;
}
