#ifndef CALM_GOALS
#define CALM_GOALS

#include "../Interfaces/goals/goals.hpp"


// TODO: this needs updated for const correctness, and possibly reworked -RG

class CalmGoals: public Goals
{

    private:
        std::vector<Dimensions> exitGoals;
        std::vector<int> nearestExit;
        Data* data;
        std::vector<Dimensions>* pedestrianCoordinatesPointer;


    public: 

        CalmGoals();

        virtual void configure(CONFIG_MAP* configMap);
        virtual void setData(Data* data);
        virtual void addExitGoals(const ObstacleSet&);
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