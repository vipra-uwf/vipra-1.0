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
        Data* data;
        Goals* goals;
        const FLOATING_NUMBER a = -2.111;
        const FLOATING_NUMBER b = 0.366;
        const FLOATING_NUMBER c = 0.966;
    
    public:
        virtual void setData(Data* initialData);
        virtual void setGoals(Goals* goal);
        virtual Data* getData();
        virtual Goals* getGoals();
        virtual void precompute();
        virtual void update(unsigned long time);

        void calculatePropulsion();
        void calculateRepulsion();
        FLOATING_NUMBER calculateDistance(
            int firstPedIndex, int secondPedIndex, std::string originSet);
        FLOATING_NUMBER calculateBeta(int pedIndex);
        void calculateNearestNeighbors();
        void calculateNearestPedNeighbors();
        bool neighborDirectionTest(
            int firstPedIndex, int secondPedIndex, std::string originSet);
        void calculatePriortiy();
        void createAisles();
};

#endif
