#ifndef CALM_GOALS
#define CALM_GOALS

#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

#include "goals.hpp"
#include "../simulation/data.hpp"
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class CalmGoals: public Goals
{

    private:
        std::vector<Dimensions> exitGoal;
        std::vector<int> nearestExit;
        Data* data;


    public: 

        CalmGoals();

        virtual void addExitGoal(std::unordered_map<std::string,
            FLOATING_NUMBER>* simulationParams);
        virtual void removeExitGoal(int exitIndex);
        virtual void clearGoals();
        virtual void calculateNearestExit(Data* data);
        virtual void determinePedestrianGoals(Data* data);
        virtual bool checkPedestianGoalsMet(Data* data, int pedestrianIndex);
        virtual bool isSimulationGoalMet(Data* data);

        unsigned int nearestGoal(Data* data, int pedestrianIndex);
        FLOATING_NUMBER calculateDistance(Data* data, 
            int pedestrianIndex, int exitGoalIndex);

};

#endif