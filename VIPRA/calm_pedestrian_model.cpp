//TODO: Fill in with actual details
#include "calm_pedestrian_model.hpp"

void CalmPedestrianModel::setData(Data* initialData)
{
    this->data = initialData;
}

void CalmPedestrianModel::precompute()
{
    //TODO: Perform precomputation for all passengers
    //Equations 6 and 7 of CALM paper
    //Decrease Force and Propulsion force in CALM code
    //result needs to be stored for each passenger

    calculatePropulsion();

}

void CalmPedestrianModel::update()
{
    //use clock, calculated force prop and calculated force rep to update positions ~Elizabeth
}

//TODO: refactor to not use pedestrian object
void CalmPedestrianModel::calculatePropulsion()
{

     FLOATING_NUMBER forceOfPropulsion;
     for(int id = 0; id < data->getPedestrianSet()->getNumPedestrians(); ++id)
     {
         data->getPedestrianSet()->setPropulsionForces(id, ((data->getPedestrianSet()->getDesiredSpeed() * data->getPedestrianSet()->getSpeeds()->at(id)) / data->getPedestrianSet()->getReactionTime()) * data->getPedestrianSet()->getMassKg());
     }

}

void CalmPedestrianModel::calculateRepulsion()
{

     FLOATING_NUMBER forceOfPropulsion;
     for(int id = 0; id < data->getPedestrianSet()->getNumPedestrians(); ++id)
     {
         data->getPedestrianSet()->setRepulsionForces(id, 1);
     }

}

void CalmPedestrianModel::calculateBeta()
{

}

void CalmPedestrianModel::printPedestrianCoordinates()
{
    this->data->printPedestrianCoordinates();
}

void CalmPedestrianModel::printObstacleCoordinates()
{
    this->data->printObstacleCoordinates();
}
