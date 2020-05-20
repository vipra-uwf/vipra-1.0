#ifndef CALMPEDESTRIANMODEL_HPP
#define CALMPEDESTRIANMODEL_HPP

//#include <vector>
//#include <utility>
#include "pedestrian_dynamics_model.hpp"
#include "data.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel
{
    public:
        virtual void setData(Data* initialData);
        virtual void precompute();
        virtual void update();
};

#endif