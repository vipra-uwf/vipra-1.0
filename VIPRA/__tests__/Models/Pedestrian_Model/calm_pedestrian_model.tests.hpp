#pragma once

#include "./../../acutest/acutest.h"

#include "../../../../Modules/PedestrianDynamicsModel/calm_pedestrian_model/calm_pedestrian_model.hpp"

namespace Calm_Pedestrian_Model_TESTS {

    void ModelReturnsCorrectDistanceMatrix(void) {
        
        CalmPedestrianSet pedestrianSet;
        CalmPedestrianModel pedestrianModel;
        DimVector pedestrianCoords = {{8,5}, {4,2}, {0,5}};

        pedestrianSet.initialize(3);
        pedestrianSet.setPedestrianCoordinates(pedestrianCoords);
        pedestrianModel.initialize(pedestrianSet);

        pedestrianModel.update(pedestrianSet, 0);

        TEST_CHECK(pedestrianModel.getPedestrianDistance(pedestrianSet, 0, 1) == 5);
        TEST_CHECK(pedestrianModel.getPedestrianDistance(pedestrianSet, 0, 2) == 8);
        TEST_CHECK(pedestrianModel.getPedestrianDistance(pedestrianSet, 1, 0) == 5);
        TEST_CHECK(pedestrianModel.getPedestrianDistance(pedestrianSet, 1, 2) == 5);
        TEST_CHECK(pedestrianModel.getPedestrianDistance(pedestrianSet, 2, 0) == 8);
        TEST_CHECK(pedestrianModel.getPedestrianDistance(pedestrianSet, 2, 1) == 5);
    }

    //First pedestrian's nearest neighbor should be equal to -1 (NOT_FOUND) since they are farthest ahead
    //Second pedestrian's nearest neighbor should be equal to 0 (First pedestrian) since they are facing the first
    //Third pedestrian's nearest neighbor should be equal to 1 (Second pedestrian) since they are facing both second and first
    //And the second pedestrian is closer
    void ModelCalculatesCorrectNearestNeighbor(void) {
        CalmPedestrianSet pedestrianSet;
        CalmPedestrianModel pedestrianModel;
        DimVector pedestrianCoords = {{8,5}, {4,2}, {0,5}};
        DimVector velocities = {{3, 4}, {5,1}, {6,2}};
        std::vector<FLOATING_NUMBER> shoulderLengths = {4, 5, 2};

        pedestrianSet.initialize(3);

        pedestrianSet.setPedestrianCoordinates(pedestrianCoords);
        pedestrianSet.setShoulderLengths(shoulderLengths);
        pedestrianSet.setVelocities(velocities);

        pedestrianModel.initialize(pedestrianSet);
        pedestrianModel.update(pedestrianSet, 0);

        TEST_CHECK(pedestrianModel.getNearestNeighbors().at(0).second == -1);
        TEST_CHECK(pedestrianModel.getNearestNeighbors().at(1).second == 0);
        TEST_CHECK(pedestrianModel.getNearestNeighbors().at(2).second == 1);
        
    }
}


#define calm_pedestrian_model_tests \
{"CALM_PEDESTRIAN_MODEL: Model Returns Correct Distance", \ 
    Calm_Pedestrian_Model_TESTS::ModelReturnsCorrectDistanceMatrix}, \
{"CALM_PEDESTRIAN_MODEL: Model Calculates Correct Nearest Neighbor", \ 
    Calm_Pedestrian_Model_TESTS::ModelCalculatesCorrectNearestNeighbor} \ 
    