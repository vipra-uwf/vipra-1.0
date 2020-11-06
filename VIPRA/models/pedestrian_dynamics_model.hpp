#ifndef PEDESTRIAN_DYNAMICS_MODEL_HPP
#define PEDESTRIAN_DYNAMICS_MODEL_HPP

#include "../simulation/data.hpp"
#include "../goals/goals.hpp"
#include "../type_definitions.hpp"

class PedestrianDynamicsModel
{
    public:
        virtual ~PedestrianDynamicsModel() = default;

        virtual void configure(CONFIG_MAP* configMap) = 0;
        virtual void initialize() = 0;
        virtual void setData(Data* initialData) = 0;
        virtual void setGoals(Goals* goal) = 0;
        virtual Data* getData() = 0;
        virtual Goals* getGoals() = 0;
        virtual void precompute() = 0;
        virtual void update(FLOATING_NUMBER time) = 0;
};

#endif
