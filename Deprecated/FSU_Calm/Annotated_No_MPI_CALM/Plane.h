/**
 * Definition of Plane class.
 *
 * @author  Mehran Sadeghi Lahijani <sadeghil@cs.fsu.edu>
 * 
 */


#ifndef PLANE_H
#define PLANE_H

#include "DataStructures.h"



class Plane{
public:
	Plane();
	Plane(Numeric t_luggage_y, Numeric t_exit_door_x, Numeric t_exit_door_y, std::vector<std::pair<int, int> > t_seat_arrangement, Obstacles t_obstacles);
	Plane(const Plane &);
	Plane(Plane &&);
	Plane & operator = (const Plane &);
	Plane & operator = (Plane &&);
	Numeric getLuggageY();
	Numeric getExitDoorX();
	Numeric getExitDoorY();
	std::vector<std::pair<int, int> > getSeatArrangement();
	Obstacles getObstacles();
	//createPlane(ifstream filename);

private:
	Numeric luggage_y;
	Numeric exit_door_x;
	Numeric exit_door_y;
	std::vector<std::pair<int, int> > seatArrangement;
	Obstacles obstacles;
	//Obstacles physical_obstacles;

};

#endif
