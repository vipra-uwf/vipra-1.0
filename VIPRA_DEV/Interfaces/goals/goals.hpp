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

#include "../../Base/simulation/data/data.hpp"
#include "../../Base/definitions/type_definitions.hpp"
#include "../../Base/definitions/dimensions.hpp"

class Goals
{
    public:
        virtual ~Goals() = default;

        virtual void configure(CONFIG_MAP* configMap) = 0;
        virtual void setData(Data* data) = 0;

        virtual void addExitGoals(const std::vector<Dimensions>& exits) = 0;
        virtual void removeExitGoal(int exitIndex) = 0;
        virtual void clearGoals() = 0;
        virtual void calculateNearestExit() = 0;
        virtual void determinePedestrianGoals() = 0;
        virtual bool checkPedestianGoalsMet(int pedestrianIndex) = 0; 
        virtual bool isSimulationGoalMet() = 0; 
        virtual Dimensions getPedestrianExitGoal(int pedestrianIndex) = 0;
};

#endif
