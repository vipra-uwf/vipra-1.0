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


    public: 

    CalmGoal();

    virtual void setExitGoal(std::unordered_map<std::string, FLOATING_NUMBER>*);
    virtual void determinePedestrianGoals(Data*);


    void isSimulationGoalMet(Data*);
    unsigned int nearestGoal(Data*, int);
    FLOATING_NUMBER calculateDistance(Data*, int, int);

};

#endif