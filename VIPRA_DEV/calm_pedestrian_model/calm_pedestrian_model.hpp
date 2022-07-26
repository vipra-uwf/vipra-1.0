#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>

#include "../Interfaces/pedestrianmodel/pedestrian_dynamics_model.hpp"
#include "../airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../calm_pedestrian_set/calm_pedestrian_set.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel
{
private:
    const FLOATING_NUMBER a = -2.4532;
    const FLOATING_NUMBER b = 0.138412;
    const FLOATING_NUMBER c = 0.87436;

    CalmPedestrianSet*                          pedestrianSet;
    ObstacleSet*                                obstacleSet; // TODO will a CALM pedestrian model only ever be used in an airplane? -- Alex
    Data*                                       data;
    Goals*                                      goals; // TODO i think this should be of type CalmGoals -- Alex
    int                                         currentPriority;

    int                                         numPedestrians;
    int                                         numObstacles;

    FLOATING_NUMBER                             *pedestrianDistanceMatrix;
    FLOATING_NUMBER                             *obstacleDistanceMatrix;

    std::vector<MovementDefinitions>            moveStates;

    std::vector<Dimensions>                     propulsionForces;
    std::vector<Dimensions>                     velocities;
    std::vector<Dimensions>                     pedestrianCoordinates;
    std::vector<Dimensions>                     obstacleCoordinates;

    std::vector<FLOATING_NUMBER>                masses;
    std::vector<FLOATING_NUMBER>                desiredSpeeds;
    std::vector<FLOATING_NUMBER>                reactionTimes;
    std::vector<FLOATING_NUMBER>                shoulderLengths;

    std::vector<std::pair<std::string, int>>    nearestNeighbors;

    void                    calculateDistanceMatrices();
    FLOATING_NUMBER         getPedestrianDistance(int first, int second);
    FLOATING_NUMBER         getObstacleDistance(int pedestrianIndex, int obstacleIndex);

public:
    void                configure(CONFIG_MAP *configMap)        override;
    void                initialize()                            override;
    void                setData(Data *initialData)              override;
    void                setGoals(Goals *goal)                   override;
    void                precompute()                            override;
    void                update(FLOATING_NUMBER time)            override;



    void                            calculatePriority();
    void                            calculatePropulsion();
    void                            calculateBeta();
    std::pair<std::string, int>     calculateNearestNeighbors(int pedestrianIndex, FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY);

    inline bool                     neighborDirectionTest(
                                        int firstPedestrianIndex, int secondPedestrianIndex,
                                        FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY,
                                        FLOATING_NUMBER secondDisplacementX, FLOATING_NUMBER secondDisplacementY);

    inline bool                     neighborSpacialTest(int firstPedestrianIndex, int secondPedestrianIndex,
                                        FLOATING_NUMBER pedestrianDisplacementX, FLOATING_NUMBER pedestrianDisplacementY,
                                        FLOATING_NUMBER secondDisplacementX, FLOATING_NUMBER secondDisplacementY,
                                        std::string originSet, FLOATING_NUMBER firstShoulderLength);

    void                            createAisles();
    bool                            updatePriority(int pedestrianIndex);

    MovementDefinitions             updateMovementState(int pedestrianIndex);
    
    Data*                           getData()                              override;
    Goals*                          getGoals()                             override;
    
    FLOATING_NUMBER                 getDistance(int firstPedestrianIndex, int secondPedestrianIndex, std::string originSet);

    ~CalmPedestrianModel();
};

#endif