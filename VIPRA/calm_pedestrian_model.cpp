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

    data->getPedestrianSet()->calculateAim();
    data->getPedestrianSet()->calculateNearestNeighbor();
    calculatePropulsion();
    calculateRepulsion();

}

void CalmPedestrianModel::update()
{
    //use clock, calculated force prop and calculated force rep to update positions ~Elizabeth
}

void CalmPedestrianModel::calculatePropulsion()
{

     FLOATING_NUMBER forceOfPropulsion;
     for(int id = 0; id < data->getPedestrianSet()->getNumPedestrians(); ++id)
     {
         std::cout << "old propulsion force: " << data->getPedestrianSet()->getPropulsionForces()->at(id) << std::endl;
         data->getPedestrianSet()->setPropulsionForces(id, ((data->getPedestrianSet()->getDesiredSpeed() - data->getPedestrianSet()->getSpeeds()->at(id)) / data->getPedestrianSet()->getReactionTime()) * data->getPedestrianSet()->getMassKg());
         std::cout << "new propulsion force: " << data->getPedestrianSet()->getPropulsionForces()->at(id) << std::endl;
         std::cout << "aim: " << data->getPedestrianSet()->getAims()->at(id) << std::endl;
         std::cout << "nearest neighbor: " << data->getPedestrianSet()->getNearestNeighbor()->at(id) << std::endl;
     }

}

void CalmPedestrianModel::calculateRepulsion()
{

     for(int id = 0; id < data->getPedestrianSet()->getNumPedestrians(); ++id)
     {
         std::cout << "old repulsion force: " << data->getPedestrianSet()->getRepulsionForces()->at(id) << std::endl;
         data->getPedestrianSet()->setRepulsionForces(id, (((calculateBeta(id)*data->getPedestrianSet()->getDesiredSpeed()) - data->getPedestrianSet()->getSpeeds()->at(id)) / data->getPedestrianSet()->getReactionTime()));
         std::cout << "new repulsion force: " << data->getPedestrianSet()->getRepulsionForces()->at(id) << std::endl;
     }

}

FLOATING_NUMBER CalmPedestrianModel::calculateBeta(int id)
{
    FLOATING_NUMBER a = -2.111;
    FLOATING_NUMBER b = 0.366;
    FLOATING_NUMBER c = 0.966;

    return (c - exp(a * (data->getPedestrianSet()->calculateDistance(id, data->getPedestrianSet()->getNearestNeighbor()->at(id)) - b)));
}

void CalmPedestrianModel::printPedestrianCoordinates()
{
    this->data->printPedestrianCoordinates();
}

void CalmPedestrianModel::printObstacleCoordinates()
{
    this->data->printObstacleCoordinates();
}
