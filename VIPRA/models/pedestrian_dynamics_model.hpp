#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include "../simulation/data.hpp"
#include "../goals/calm_goal.hpp"

class PedestrianDynamicsModel
{
    public:
        virtual void setData(Data* initialData) = 0;
        virtual void setGoal(CalmGoal* goal) = 0;
        virtual Data* getData() = 0;
        virtual CalmGoal* getGoal() = 0;
        virtual void precompute() = 0;
        virtual void update() = 0;
};

#endif
