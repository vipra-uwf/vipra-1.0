#include "calm_pedestrian_set.hpp"

void CalmPedestrianSet::initialize(size_t pedestrianCount)
{
    this->numPedestrians         = pedestrianCount;
    this->velocities             = DimVector(pedestrianCount, Dimensions{STARTING_VELOCITY_X, STARTING_VELOCITY_Y});
    this->speedsMetersPerSecond  = std::vector<FLOATING_NUMBER>(pedestrianCount, STARTING_SPEED);
    this->massesKg               = std::vector<FLOATING_NUMBER>(pedestrianCount, STARTING_MASS);
    this->reactionTimes          = std::vector<FLOATING_NUMBER>(pedestrianCount, STARTING_REACTION_TIME);
    this->desiredSpeeds          = std::vector<FLOATING_NUMBER>(pedestrianCount, STARTING_DESIRED_SPEED);
    this->propulsionForces       = DimVector(pedestrianCount, Dimensions{STARTING_PROP_FORCE, STARTING_PROP_FORCE});
    this->nearestNeighbors       = std::vector<std::pair<std::string, int>>(pedestrianCount, {"P", STARTING_NEAREST_NEIGHBOR});
    this->startingAisles         = std::vector<int>(pedestrianCount, 0);
    this->shoulderLengths        = std::vector<FLOATING_NUMBER>(pedestrianCount, STARTING_SHOULDER_WIDTH);
    this->raceStatus             = std::vector<RaceStatus>(pedestrianCount, RaceStatus::NO_RACE);
    this->raceCounter            = std::vector<int>(pedestrianCount, 0);
    this->opponentIDs            = std::vector<int>(pedestrianCount, 0);
    this->racePositions          = DimVector(pedestrianCount, Dimensions{STARTING_PROP_FORCE, STARTING_PROP_FORCE});
    this->raceFinished           = std::vector<bool>(pedestrianCount, false);
    this->released               = std::vector<bool>(pedestrianCount, false);

    this->setIds(std::vector(pedestrianCount, 0));
    std::iota(this->ids.begin(), this->ids.end(), 0);
}