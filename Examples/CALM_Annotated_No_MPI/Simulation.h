/**
 * Definition of Simulation class.
 *
 * @author  Mehran Sadeghi Lahijani <sadeghil@cs.fsu.edu>
 * 
 */


#ifndef Simulation_h
#define Simulation_h

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
#include <random>
#include <math.h>

#include "DataStructures.h"
#include "Plane.h"
using namespace std;

class Simulation{
public:
    Simulation();
    Simulation(Numeric mean_t, Numeric stddev_t, Numeric Intersection_Distance_Threshold, Numeric Intersection_Speed_Coefficient, Numeric Aligning_Speed_Coefficient, Numeric Toward_Aisle_Speed_Coefficient, Numeric Release_Threshold);
    Numeric getMean();
    Numeric getStddev();
    int getOutputIndex();

    void setMean(Numeric mean_t);
    void setStddev(Numeric stddev_t);
    void setOutputIndex(int output_index_t);
    void InitializeGrids(Passengers& passengers_t, vector<int> *& passengers_grid, const Obstacles& obstacles_t, vector<int>*& obstacles_grid_t, const Numeric& cell_length, const Numeric& cell_width, const int& y_dim, const Numeric& max_y);
    void UpdatePassengersGrid(Passengers& passengers, vector<int> *& passengers_grid, vector<int> *& new_passengers_grid, const Numeric& cell_length, const Numeric& cell_width, const int& y_dim, const Numeric& max_y, const int& grid_size);
    void UpdatePassenger(Aim &p_aim, const Numeric& p_position_x, const Numeric& p_position_y, const Numeric& luggage_location_y, int& p_wait_time, bool& has_released, const Numeric& p_seat_position_x, const Numeric& p_seat_position_y, vector<int>& holds, const int& priority, vector<bool>& aisle_permission, const Numeric& plane_exit_x, const Numeric& plane_exit_y, RaceStatus& p_race_status, int& OpID, bool& p_race_finished, Numeric& race_position_x, Numeric& race_position_y, RaceStatus& op_race_status, int& op_race_OpID, bool& op_race_is_finished, Numeric& op_race_position_x, Numeric& op_race_position_y, const Numeric& ID, const Numeric& time_step, int& numberOfPassesgersInPlane, const Numeric& Release_Threshold, ofstream& output);
    
    bool checkPathInCell(const vector<int>& cell, const int& passenger_ID, const Obstacles& obstacles_t, const Passengers& passengers_t);
    Numeric getSeparation(const Numeric& main_position_x, const Numeric& main_position_y, const Aim& main_aim_t, const Numeric& sec_position_x, const Numeric& sec_position_y, const Aim& sec_aim_t);
    void getNearestPassenger(Numeric& NID, Numeric& N_position_x, Numeric& N_position_y, Numeric& N_distance, const int& passenger_ID, vector<int> *& passengers_grid_t, const Numeric& exit_position, const int& y_dim, Passengers& passengers_t, const int& grid_size);
    Numeric DecreaseSpeed(const Numeric& coeff, const Numeric& distance, const Numeric& cell_width);
    void Propulsive_Force(const Aim & aim, const Numeric& position_y, const Numeric& mass, const Numeric& velocity_x, const Numeric& velocity_y, const Numeric& time_step, const Numeric& desired_speed, Numeric& forces_x, Numeric& forces_y);
    Numeric getObsSeparation(const Numeric & main_position_x, const Numeric & main_position_y, const Aim& main_aim_t, const Numeric & obs_position_x, const Numeric & obs_position_y);
    void EulerMethod(const RaceStatus& race_status, const Numeric& force_x, const Numeric& force_y, const Numeric& mass, Numeric& velocity_x, Numeric& velocity_y, Numeric& position_x, Numeric& position_y, const Aim& aim, const Numeric& seat_position_x, const Numeric& desired_speed, const Numeric& delta);
    void checkBehind(vector<int>& cell, Passengers& passengers, int i, int size);
    //Passengers_Map::iterator getPassengerByID(Passengers_Map& psg_map, int ID);
    void split(const string &s, char delim, vector<string> &elems);
    vector<Numeric> Initialize(Passengers &passengers_t, Obstacles &obstacles_t, Plane &plane_t, vector<string>& xyz_obs);
    void initializePermissions(vector<int>& holds, vector<bool>& aisle_permission, const vector<pair<int, int> >& arrangement);
    bool blockedPath(const int& passenger_t, const std::vector<int>* obstacles_grid_t, const int& y_dim, const Obstacles& obstacles_t, const Passengers& passengers_t, const int& grid_size);
    void raceDetection(Passengers& passengers, const int& ID, const Numeric& time_step);
    void WriteOutput(const Passengers & passengers_t, int n, ofstream& output, const vector<string>& xyz_obs);
    int Run(ofstream& output);
    void getNearestInCell(const vector<int>& cell, const  int& passenger_ID, NearestPassenger& nearest_t, Passengers& passengers_t);
    //void setDesiredSpeeds(Passengers_Map &passengers_t);

private:
    Numeric mean;
    Numeric stddev;

    Numeric Intersection_Distance_Threshold;
    Numeric Intersection_Speed_Coefficient;
    Numeric Aligning_Speed_Coefficient;
    Numeric Toward_Aisle_Speed_Coefficient;
    Numeric Release_Threshold;


    int output_index;
};



#endif /* Simulation_h */
