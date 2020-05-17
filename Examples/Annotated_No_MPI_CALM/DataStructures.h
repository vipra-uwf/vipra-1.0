/**
 * Definition of some data types and enums.
 *
 * @author  Mehran Sadeghi Lahijani <sadeghil@cs.fsu.edu>
 *
 */

#ifndef DataStructures_h
#define DataStructures_h

#include <vector>
#include <chrono>
#include <array>
#include <map>

#define NumberOfPassengers 144
#define NumberOfObstacles 593

typedef float Numeric;
typedef std::vector<Numeric> NumericVector;




typedef std::chrono::high_resolution_clock::time_point Time;
enum PassengerTypes {FIRST_CLASS, BUSINESS, ECONOMY};
typedef PassengerTypes PassengerType;

//REFER TO CALM_plane_orientation.png
//DOWN_TO_AISLE - FOR PASSENGERS WHO ARE ON THE LEFT SIDE OF PLANE (ASSUMING FACING FRONT OF PLANE) - decreasing y coordinate
//UP_TO_AISLE - FOR PASSENGERS WHO ARE ON THE RIGHT SIDE OF THE PLANE (ASSUMING FACING FRONT OF PLANE) - increasing y coordinate

//ALIGNING - AFTER UNLOADING BAGGAGE, COME TO CENTER OF THE AISLE
//IN_AISLE - PASSENGER IS IN THE AISLE - increasing x coordinate
//TOWARD_EXIT - TURN TOWARD EXIT - increasing y coordinate to exit plane
//LOADONG_LUGGAGE - COME DOWN/UP TO AISLE FIRST, THEN WAIT TO SIMULATE UNLOADING LUGGAGE, GET INTO CENTER OF AISLE
//OUT - PASSENGER HAS EXITED THE SIMULATION
enum PassengerAims {DOWN_TO_AISLE, UP_TO_AISLE, ALIGNING, IN_AISLE, TOWARD_EXIT, LOADONG_LUGGAGE, OUT};
typedef PassengerAims Aim;

enum PassengersRaceStatus {IN_RACE, WINNER, LOOSER, NO_RACE};
typedef PassengersRaceStatus RaceStatus;




struct PassengersStruct
{
	Numeric mass[NumberOfPassengers]; //mass of passenger
    Numeric priority[NumberOfPassengers]; //used to determine permission of leaving
    int waitTime[NumberOfPassengers]; //time to wait to get luggage
    bool inPlane[NumberOfPassengers]; //if current passenger is in plane
    Aim aim[NumberOfPassengers]; //current direction the passenger is facing
    Numeric position_x[NumberOfPassengers]; //current x coordinate position
    Numeric position_y[NumberOfPassengers]; //current y coordinate position
    Numeric velocity_x[NumberOfPassengers]; //current velocity moving left or right
    Numeric velocity_y[NumberOfPassengers]; //current velocity moving up or down
   	Numeric acceleration_x[NumberOfPassengers]; //current acceleration rate left or right
   	Numeric acceleration_y[NumberOfPassengers]; //current acceleration rate up or down
    Numeric seat_position_x[NumberOfPassengers]; //x coordinate for current passengers seat
    Numeric seat_position_y[NumberOfPassengers]; //y coordinate for current passengers seat
    bool has_released[NumberOfPassengers]; //used as a flag - we want to ensure passengers in back rows wait
																					//until passengers in front row get into the aisle just enough for people to stand up -
																					//passengers are locked until they can move
    Numeric desiredSpeed[NumberOfPassengers]; //maximum speed for current passenger that can be achieved
    int ID[NumberOfPassengers]; //current passenger ID
    int arr_index_in_grid[NumberOfPassengers]; //location of current passenger in the grid.
																							//grid contains cells, each iteration: update grid, and each passenger is assigned to a cell,
																							//and that is the index of the cell (multiple passengers can be in one cell)
    Numeric race_position_x[NumberOfPassengers]; //x coordinate of a race
    Numeric race_position_y[NumberOfPassengers]; //y coordinate of a race
    int race_opID[NumberOfPassengers]; //opponent ID - who the current passenger is racing
    bool race_is_finished[NumberOfPassengers]; //race has finished
    Numeric race_counter[NumberOfPassengers]; //how long we have waited and making sure we have waited long enough to determine if it's actually a race
    RaceStatus race_status[NumberOfPassengers]; //race status for current passenger
    Numeric force_x[NumberOfPassengers]; //x axis force of current passenger
    Numeric force_y[NumberOfPassengers]; //y axis force of current passenger
    Numeric nearest_ID[NumberOfPassengers]; //nearest passenger to current passenger
    Numeric nearest_position_x[NumberOfPassengers]; //x coordinate position of nearest passenger to current passenger
    Numeric nearest_position_y[NumberOfPassengers]; //y coordinate position of nearest passenger to current passenger
    Numeric nearest_distance[NumberOfPassengers]; //distance to nearest passenger
};


typedef PassengersStruct Passengers;
//typedef std::multimap<Numeric, Numeric> Passengers_Map;


struct ObstaclesStruct{
	Numeric positions_x [NumberOfObstacles];
	Numeric positions_y[NumberOfObstacles];
};

typedef ObstaclesStruct Obstacles;

struct NearestPassengerStruct {
    Numeric ID;
    Numeric position_x;
    Numeric position_y;
    Numeric distance;
};
typedef NearestPassengerStruct NearestPassenger;


//typedef std::array<float,2> Vector2D;
#endif /* DataStructures_h */
