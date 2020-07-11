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


class Goal
{
    private:
    //keep track of final goals
    std::vector<Dimensions> exitGoal;


    public:
        Goal();
        void setExitGoal(std::vector<Dimensions>);
        //void determinePedestrianGoals(Data*, Time); -Need more information on time class - elizabeth
        void determinePedestrianGoals(Data*);
        //void isSimulationGoalMet(Data*, Time); -Need more information on time class - elizabeth
        void findPath(Data*, int, int);
        bool isBlocked(Data*, int, std::string);
        bool hasOpening(Data*, int);
        void isSimulationGoalMet(Data*);
        unsigned int nearestGoal(Data*, int);
        FLOATING_NUMBER calculateDistance(Data*, int, int);
};

#endif
