#include "pedestrian_set.hpp"

PedestrianSet::PedestrianSet()
{
    numPedestrians = 0;
    //desiredSpeed = 1; 
    //reactionTime = .25;
    //massKg = 70;
}

void PedestrianSet::addPedestrian(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate)
{
    this->xCoordinates.push_back(xCoordinate);
    this->yCoordinates.push_back(yCoordinate);
    //nearestNeighbor.push_back(-1);

    goalXCoordinates.push_back(0);
    goalYCoordinates.push_back(0);
    //aims.push_back("NULL");

    //speeds.push_back(0);
    propulsionForces.push_back(0);
    repulsionForces.push_back(0);

    numPedestrians++;
}

void PedestrianSet::setSpeed(int id, FLOATING_NUMBER speed)
{
    speedsMetersPerSecond.at(id) = speed;
}

void PedestrianSet::setPropulsionForces(int id, FLOATING_NUMBER propulsionForce)
{
    propulsionForces.at(id) = propulsionForce;
}

void PedestrianSet::setRepulsionForces(int id, FLOATING_NUMBER repulsionForce)
{
    repulsionForces.at(id) = repulsionForce;
}

/*void PedestrianSet::calculateAim()
{
    for (int id = 0; id < numPedestrians; ++id)
    {
    if(yCoordinates.at(id) > 0)
    {
        aims.at(id) = "DOWN_TO_ISLE";
    }

    else if(yCoordinates.at(id) < 0)
    {
        aims.at(id) = "UP_TO_ISLE";
    }
    else
    {
        aims.at(id) = "IN_ISLE";
    }
    }
}*/

void PedestrianSet::calculateNearestNeighbor()
{
    //"speeds" have 2 dimension and therefore indicate direction so they replace "aims"? -valkor
    /*
    for (int id = 0; id < numPedestrians; ++id)
    {

        if(aims.at(id) == "DOWN_TO_ISLE" || aims.at(id) == "UP_TO_ISLE")
        {
            int position = (id % 3) + 1;

            switch(position)
            {
            case 1:
                nearestNeighbor.at(id) = id + 1;
                break;
            case 2:
                if(calculateDistance(id, id - 1) < calculateDistance(id + 1, id))
                {
                    nearestNeighbor.at(id) = id - 1;
                }
                else
                    nearestNeighbor.at(id) = id + 1;
                break;

            case 3:
                nearestNeighbor.at(id) = id - 1;
                break;
            }

        }

        else
        {
            int minimumRange = 6; //minimum number pedestrians that need to be checked for nearest while in isle
            if(id < minimumRange)
            {
                int nearest = -1; //-1 will act as a null since there isn't a -1 index position in a vector
                for(int index = 0; index < minimumRange; ++index) //search initial minimum range
                {
                    if(index != id) //make sure we are not checking against the current pedestrian
                    {
                        if(getAims()->at(index) == "IN_ISLE") //check to see if the index pedestrian is in the isle or not
                        {
                            if(nearest == -1) //if there isnt a nearest passenger yet, make the first person in the isle the nearest
                            {
                                nearest = index;
                            }
                            else if(calculateDistance(index, id) < calculateDistance(nearest, id)) //if there is a pedestrian already set to nearest, check to see if the next found passenger in the isle is closer
                            {
                                nearest = index;
                            }
                        }
                    }
                }
                if(nearest != 1)
                {
                    nearestNeighbor.at(id) = nearest;
                }
            }
            else
            {
                int nearest = -1;
                for(int index = (id-(minimumRange/2)); index < (id+(minimumRange/2)); ++index)
                {
                    if(index != id)
                    {
                        if(getAims()->at(index) == "IN_ISLE")
                        {
                            if(nearest == -1)
                            {
                                nearest = index;
                            }
                            else if(calculateDistance(index, id) < calculateDistance(nearest, id))
                            {
                                nearest = index;
                            }
                        }
                    }
                }
                if(nearest != 1)
                {
                    nearestNeighbor.at(id) = nearest;
                }
            }
        }
    }
    */
}

FLOATING_NUMBER PedestrianSet::calculateDistance(int idOfFirst, int idOfSecond)
{
    FLOATING_NUMBER xDistance = pow((xCoordinates.at(idOfFirst) - xCoordinates.at(idOfSecond)), 2);
    FLOATING_NUMBER yDistance = pow((yCoordinates.at(idOfFirst) - yCoordinates.at(idOfSecond)), 2);
    return (sqrt(xDistance + yDistance));
}

int PedestrianSet::getNumPedestrians()
{
    return this->numPedestrians;
}

FLOATING_NUMBER PedestrianSet::getDesiredSpeed(int i)
{
    return this->speedsMetersPerSecond.at(i);
}

FLOATING_NUMBER PedestrianSet::getMassKg(int i)
{
    return this->massesKg.at(i);
}

FLOATING_NUMBER PedestrianSet::getReactionTimeSeconds(int i)
{
    return this->reactionTimesSeconds.at(i);
}



int PedestrianSet::getNearestNeighbor(int i)
{
    return this->nearestNeighbors.at(i);
}

FLOATING_NUMBER PedestrianSet::getXCoordinate(int i)
{
    return this->xCoordinates.at(i);
}

FLOATING_NUMBER PedestrianSet::getYCoordinate(int i)
{
    return this->yCoordinates.at(i);
}

FLOATING_NUMBER PedestrianSet::getSpeed(int i)
{
    return this->speedsMetersPerSecond.at(i);
}

FLOATING_NUMBER PedestrianSet::getPropulsionForce(int i)
{
    return this->propulsionForces.at(i);
}

FLOATING_NUMBER PedestrianSet::getRepulsionForce(int i)
{
    return this->repulsionForces.at(i);
}
