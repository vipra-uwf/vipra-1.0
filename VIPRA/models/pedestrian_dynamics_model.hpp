#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include "../simulation/data.hpp"
#include "../goals/calm_goals.hpp"

class PedestrianDynamicsModel
{
    public:
        virtual void setData(Data* initialData) = 0;
        virtual void setGoals(Goals* goal) = 0;
        virtual Data* getData() = 0;
        virtual Goals* getGoals() = 0;
        virtual void precompute() = 0;
        virtual void update(FLOATING_NUMBER time) = 0;
};

#endif
