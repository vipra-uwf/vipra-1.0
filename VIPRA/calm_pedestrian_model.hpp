#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

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
        virtual void calculatePropulsion(Pedestrian* currentPedestrian);
        virtual void printPedestrianCoordinates();
        virtual void printObstacleCoordinates();

    private:
        Data* data;

};

#endif
