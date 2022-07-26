/**
 * Implementation of Plane class. Objects of this class represent a plane.
 *
 * @author  Mehran Sadeghi Lahijani <sadeghil@cs.fsu.edu>
 * 
 */


#include "Plane.h"


Plane::Plane(){
	//defaurt constructor
}

Plane::Plane(Numeric t_luggage_y, Numeric t_exit_door_x, Numeric t_exit_door_y, std::vector<std::pair<int, int> > t_seat_arrangement, Obstacles t_obstacles){
	luggage_y=t_luggage_y;
	exit_door_x=t_exit_door_x;
	exit_door_y=t_exit_door_y;
	seatArrangement = t_seat_arrangement;
	obstacles= t_obstacles;
}
Plane::Plane(const Plane & p){
	luggage_y = p.luggage_y;
	exit_door_x = p.exit_door_x;
	exit_door_y = p.exit_door_y;
	seatArrangement = p.seatArrangement;
	obstacles= p.obstacles;
}
Plane::Plane(Plane && p){
	luggage_y = std::move(p.luggage_y);
	exit_door_x = std::move(p.exit_door_x);
	exit_door_y = std::move(p.exit_door_y);
	seatArrangement = std::move(p.seatArrangement);
	obstacles= std::move(p.obstacles);
}
Plane & Plane::operator = (const Plane & p){
	luggage_y = p.luggage_y;
	exit_door_x = p.exit_door_x;
	exit_door_y = p.exit_door_y;
	seatArrangement = p.seatArrangement;
	obstacles= p.obstacles;
	return *this;
}
Plane & Plane::operator = (Plane && p){
	luggage_y = std::move(p.luggage_y);
	exit_door_x = std::move(p.exit_door_x);
	exit_door_y = std::move(p.exit_door_y);
	seatArrangement = std::move(p.seatArrangement);
	obstacles= std::move(p.obstacles);
	return *this;
}
Numeric Plane::getLuggageY(){
	return luggage_y;
}
Numeric Plane::getExitDoorX(){
	return exit_door_x;
}

Numeric Plane::getExitDoorY(){
	return exit_door_y;
}

std::vector<std::pair<int, int> > Plane::getSeatArrangement(){
	return seatArrangement;
}


Obstacles Plane::getObstacles(){
	return obstacles;
}
