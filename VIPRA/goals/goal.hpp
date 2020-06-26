//should specify functionality for determining whether goals are met
//specification of the goal
    //time
    //state of the obstacles and pedestrians

#ifndef GOAL_HPP
#define GOAL_HPP 

#include <vector>

#include "../simulation/data.hpp"
#include "../type_definitions.hpp"

class Goal
{
    private:
    //keep track of final goals
    //TODO: create dimension struct for velocity and goals? -elizabeth
    std::vector<std::vector<FLOATING_NUMBER>> exitGoal;


    public:
         Goal();
         void initializeGoals(Data*);
         void setExitGoal(int, FLOATING_NUMBER);
         //void determinePedestrianGoals(Data*, Time); -Need more information on time class - elizabeth
         void determinePedestrianGoals(Data*);
         //void isSimulationGoalMet(Data*, Time); -Need more information on time class - elizabeth
         void isSimulationGoalMet(Data*);
};

#endif
