#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <vector>
#include <algorithm>
#include <math.h>

#include "pedestrian_dynamics_model.hpp"
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
        const FLOATING_NUMBER a = -2.4532;
        const FLOATING_NUMBER b = 0.138412;
        const FLOATING_NUMBER c = 0.87436;
    
    public:
        virtual void configure(CONFIG_MAP* configMap);
        virtual void initialize();
        virtual void setData(Data* initialData);
        virtual void setGoals(Goals* goal);
        virtual Data* getData();
        virtual Goals* getGoals();
        virtual void precompute();
        virtual void update(FLOATING_NUMBER time);

        void calculatePropulsion();
        FLOATING_NUMBER calculateDistance(
            int firstPedestrianIndex, int secondPedestrianIndex, 
            std::string originSet);
        void calculateBeta();
        std::pair<std::string, int> calculateNearestNeighbors(
            int pedestrianIndex);
        std::pair<std::string, int> ompCalculateNearestNeighbor(
                int pedestrianIndex);
        bool neighborDirectionTest(
            int firstPedestrianIndex, int secondPedestrianIndex, 
            std::string originSet);
        void calculatePriority();
        void createAisles();
        MovementDefinitions updateMovementState(int pedestrianIndex);
        bool updatePriority(int pedestrianIndex);
};

#endif
