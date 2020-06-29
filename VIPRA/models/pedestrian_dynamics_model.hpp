#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include "../simulation/data.hpp"

class PedestrianDynamicsModel
{
    public:
        virtual void setData(Data* initialData) = 0;
        virtual Data* getData() = 0;
        virtual void precompute() = 0;
        virtual void update() = 0;
};

#endif
