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
    private:
        //keep track of final goals
        //exit locations
        std::vector<Dimensions> exitGoals;


    public:
        Goal();
        void addExitGoal(std::unordered_map<std::string, FLOATING_NUMBER>*);
        //add a removeExitGoal(std::unordered_map<std::string, FLOATING_NUMBER>*) - identify the goal that is being removed
        //add a clearGoals() - clears the vector of goals
        //virtual void determinePedestrianGoals(Data*, Time) = 0; -Need more information on time class - elizabeth
        virtual void determinePedestrianGoals(Data*) = 0;
        //void isSimulationGoalMet(Data*, Time); -Need more information on time class - elizabeth
        void isSimulationGoalMet(Data*);        
        
        //remove the below from this class
        void findPath(Data*, int, int);
        bool isBlocked(Data*, int, std::string);
        bool hasOpening(Data*, int);
        unsigned int nearestGoal(Data*, int);
        FLOATING_NUMBER calculateDistance(Data*, int, int);
};

#endif
