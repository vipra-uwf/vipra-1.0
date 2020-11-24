#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <vector>
#include <algorithm>
#include <math.h>

#include "pedestrian_dynamics_model.hpp"
#include "../simulation/data.hpp"
#include "../goals/calm_goals.hpp"
#include "../entity_sets/airplane_obstacle_set.hpp"
#include "../entity_sets/calm_pedestrian_set.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel
{
    private:
        CalmPedestrianSet* pedestrianSet;
        ObstacleSet* obstacleSet; // TODO will a CALM pedestrian model only ever be used in an airplane? -- Alex 
        Data* data;
        Goals* goals; // TODO i think this should be of type CalmGoals -- Alex
        int currentPriority;
        const FLOATING_NUMBER a = -2.111;
        const FLOATING_NUMBER b = 0.366;
        const FLOATING_NUMBER c = 0.966;
    
    public:
        virtual void configure(CONFIG_MAP* configMap);
        virtual void initialize();
        virtual void setData(Data* initialData);
        virtual void setGoals(Goals* goal);
        virtual Data* getData();
        virtual Goals* getGoals();
        virtual void precompute();
        virtual void update(FLOATING_NUMBER time);

        void calculatePropulsion(int pedestrianIndex);
        void calculateRepulsion(int pedestrianIndex);
        FLOATING_NUMBER calculateDistance(
            int firstPedIndex, int secondPedestrianIndex, std::string originSet);
        FLOATING_NUMBER calculateBeta(int pedestrianIndex);
        std::pair<std::string, int> calculateNearestNeighbors(int pedestrianIndex);
        int calculateNearestPedNeighbors(int pedestrianIndex);
        bool neighborDirectionTest(
            int firstPedestrianIndex, int secondPedestrianIndex, std::string originSet);
        void calculatePriority();
        void createAisles();
        MovementDefinitions updateMovementState(int pedestrianIndex);
        bool updatePriority(int pedestrianIndex);
};

#endif
