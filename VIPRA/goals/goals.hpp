//should specify functionality for determining whether goals are met
//specification of the goal
    //time
    //state of the obstacles and pedestrians

#ifndef GOALS_HPP
#define GOALS_HPP 

#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

//name change - Goals
class Goals
{

    public:
        virtual ~Goals() = default;

        virtual void setData(Data* data) = 0;
        virtual void addExitGoal(std::unordered_map<std::string,
            FLOATING_NUMBER>* simulationParams) = 0;
        virtual void removeExitGoal(int exitIndex) = 0;
        virtual void clearGoals() = 0;
        virtual void calculateNearestExit() = 0;
        virtual void determinePedestrianGoals() = 0;
        virtual bool checkPedestianGoalsMet(int pedestrianIndex) = 0; 
        virtual bool isSimulationGoalMet() = 0; 
};

#endif
