//should specify functionality for determining whether goals are met
//specification of the goal
    //time
    //state of the obstacles and pedestrians

#ifndef GOAL_HPP
#define GOAL_HPP 

#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

//name change - Goals
class Goal
{

    public:
        virtual void addExitGoal(std::unordered_map<std::string, FLOATING_NUMBER>* simulationParams) = 0;
        virtual void removeExitGoal(int exitIndex) = 0;
        virtual void clearGoals() = 0;
        virtual void calculateNearestExit(Data* data) = 0;
        virtual void determinePedestrianGoals(Data* data) = 0;
        virtual bool checkPedestianGoalsMet(Data* data, int pedestrianIndex) = 0; // added these two methods 
        virtual bool isSimulationGoalMet(Data* data) = 0; // added these two methods 
};

#endif
