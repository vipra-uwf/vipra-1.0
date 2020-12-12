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
        std::vector<Dimensions>* pedestrianCoordinatesPointer;


    public: 

        CalmGoals();

        virtual void configure(CONFIG_MAP* configMap);
        virtual void setData(Data* data);
        virtual void addExitGoal(std::unordered_map<std::string,
            FLOATING_NUMBER>* simulationParams);
        virtual void removeExitGoal(int exitIndex);
        virtual void clearGoals();
        virtual void calculateNearestExit();
        virtual void determinePedestrianGoals();
        virtual bool checkPedestianGoalsMet(int pedestrianIndex);
        virtual bool isSimulationGoalMet();
        virtual Dimensions getPedestrianExitGoal(int pedestrianIndex);

        void createPedestrianCoordinatesPointer();
        unsigned int nearestGoal(int pedestrianIndex);
        FLOATING_NUMBER calculateDistance(int pedestrianIndex, 
            int exitGoalIndex);

};

#endif