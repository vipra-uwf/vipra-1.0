#ifndef CALM_GOAL
#define CALM_GOAL

#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

#include "goal.hpp"
#include "../simulation/data.hpp"
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class CalmGoal: public Goal
{

    private:
    std::vector<Dimensions> exitGoal;
    std::vector<int> nearestExit;


    public: 

    CalmGoal();

    virtual void addExitGoal(std::unordered_map<std::string, FLOATING_NUMBER>* simulationParams);
    virtual void removeExitGoal(int exitIndex);
    virtual void clearGoals();
    virtual void calculateNearestExit(Data* data);
    virtual void determinePedestrianGoals(Data* data);
    virtual bool checkPedestianGoalsMet(Data* data, int pedestrianIndex);
    virtual bool isSimulationGoalMet(Data* data);

    unsigned int nearestGoal(Data* data, int pedestrianIndex);
    FLOATING_NUMBER calculateDistance(Data* data, int pedestrianIndex, int exitGoalIndex);

};

#endif