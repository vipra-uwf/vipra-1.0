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

//#define NumberOfPassengers 182
#define NumberOfPassengers 144
//#define NumberOfPassengers 201
//#define NumberOfPassengers 50

//#define NumberOfObstacles 772
#define NumberOfObstacles 593
//#define NumberOfObstacles 972
//#define NumberOfObstacles 321

typedef float Numeric;
typedef std::vector<Numeric> NumericVector;




typedef std::chrono::high_resolution_clock::time_point Time;
enum PassengerTypes {FIRST_CLASS, BUSINESS, ECONOMY};
typedef PassengerTypes PassengerType;

enum PassengerAims {DOWN_TO_AISLE, UP_TO_AISLE, ALIGNING, IN_AISLE, TOWARD_EXIT, LOADONG_LUGGAGE, OUT};
typedef PassengerAims Aim;

enum PassengersRaceStatus {IN_RACE, WINNER, LOOSER, NO_RACE};
typedef PassengersRaceStatus RaceStatus;



struct PassengersStruct
{
	Numeric mass[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric priority[NumberOfPassengers] __attribute__((aligned(32)));
    int waitTime[NumberOfPassengers] __attribute__((aligned(32)));
    bool inPlane[NumberOfPassengers] __attribute__((aligned(32)));
    Aim aim[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric position_x[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric position_y[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric velocity_x[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric velocity_y[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric acceleration_x[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric acceleration_y[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric seat_position_x[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric seat_position_y[NumberOfPassengers] __attribute__((aligned(32)));
    bool has_released[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric desiredSpeed[NumberOfPassengers] __attribute__((aligned(32)));
    int ID[NumberOfPassengers] __attribute__((aligned(32)));
    int arr_index_in_grid[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric race_position_x[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric race_position_y[NumberOfPassengers] __attribute__((aligned(32)));
    int race_opID[NumberOfPassengers] __attribute__((aligned(32)));
    bool race_is_finished[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric race_counter[NumberOfPassengers] __attribute__((aligned(32)));
    RaceStatus race_status[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric force_x[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric force_y[NumberOfPassengers] __attribute__((aligned(32)));
    int nearest_ID[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric nearest_position_x[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric nearest_position_y[NumberOfPassengers] __attribute__((aligned(32)));
    Numeric nearest_distance[NumberOfPassengers] __attribute__((aligned(32)));
};

	
typedef PassengersStruct Passengers;
//typedef std::multimap<Numeric, Numeric> Passengers_Map;


struct ObstaclesStruct{
    Numeric positions_x [NumberOfObstacles] __attribute__((aligned(32)));
    Numeric positions_y[NumberOfObstacles] __attribute__((aligned(32)));
};

typedef ObstaclesStruct Obstacles;

struct NearestPassengerStruct {
    int ID;
    Numeric position_x;
    Numeric position_y;
    Numeric distance;
};
typedef NearestPassengerStruct NearestPassenger;


//typedef std::array<float,2> Vector2D;
#endif /* DataStructures_h */

