#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <vector>
#include <algorithm>
#include <math.h>

#include "pedestrian_dynamics_model.hpp"
#include "../simulation/data.hpp"
#include "../goals/calm_goals.hpp"
#include "../entity_sets/calm_pedestrian_set.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel
{
    private:
        CalmPedestrianSet* pedSet;
        ObstacleSet* obSet;
        Data* data;
        Goals* goals;
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

        void calculatePropulsion(int pedIndex);
        void calculateRepulsion(int pedIndex);
        FLOATING_NUMBER calculateDistance(
            int firstPedIndex, int secondPedIndex, std::string originSet);
        FLOATING_NUMBER calculateBeta(int pedIndex);
        std::pair<std::string, int> calculateNearestNeighbors(int pedIndex);
        int calculateNearestPedNeighbors(int pedIndex);
        bool neighborDirectionTest(
            int firstPedIndex, int secondPedIndex, std::string originSet);
        void calculatePriority();
        void createAisles();
        MovementDefinitions updateMovementState(int pedIndex);
        bool updatePriority(int pedIndex);
};

#endif
