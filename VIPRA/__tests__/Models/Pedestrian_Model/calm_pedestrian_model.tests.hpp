#pragma once

#include "./../../acutest/acutest.h"

#include "../../../../Modules/PedestrianDynamicsModel/calm_pedestrian_model/calm_pedestrian_model.hpp"
#include "../../../Base/definitions/state.hpp"
#include "../../MOCKS/pedestrian_set/pedestrian_set.mock.hpp"
#include "../../../../Modules/Goals/calm_goals/calm_goals.hpp"
#include "../../../../Modules/MapLoader/Point_Map_Loader/point_map_loader.hpp"
#include "../../../../Modules/ObstacleSet/airplane_obstacle_set/airplane_obstacle_set.hpp"
#include "../../../../VIPRA/Base/inputdataloader/input_json_reader/input_json_reader.hpp"
#include "../../TEST_Values/Calm_Pedestrian_Model_VALUES/calm_model_VALUES.hpp"

namespace Calm_Pedestrian_Model_TESTS {

    void ModelReturnsCorrectDistanceMatrix(void) {
        CalmPedestrianSet pedestrianSet;
        CalmPedestrianModel pedestrianModel;
        CalmGoals goals;
        AirplaneObstacleSet obs;
        DimVector pedestrianCoords = {{8,5}, {4,2}, {0,5}};
        ENTITY_SET pedestrians = {{"pedestrians", pedestrianCoords}};

        pedestrianSet.initialize(pedestrians);
        pedestrianSet.setPedestrianCoordinates(pedestrianCoords);

        pedestrianModel.initialize(pedestrianSet, obs, goals);
        pedestrianModel.calculateDistanceMatrices(pedestrianSet);

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
        AirplaneObstacleSet obs;
        CalmGoals goals;
        DimVector pedestrianCoords = {{8,5}, {4,2}, {0,5}};
        DimVector velocities = {{3, 4}, {5,1}, {6,2}};
        std::vector<FLOATING_NUMBER> shoulderLengths = {4, 5, 2};
        ENTITY_SET pedestrians = {{"pedestrians", pedestrianCoords}};


        pedestrianSet.initialize(pedestrians);
        pedestrianSet.setPedestrianCoordinates(pedestrianCoords);

        pedestrianSet.initialize(pedestrians);
        pedestrianSet.setPedestrianCoordinates(pedestrianCoords);
        pedestrianSet.setShoulderLengths(shoulderLengths);
        pedestrianSet.setVelocities(velocities);

        pedestrianModel.initialize(pedestrianSet, obs, goals);
        pedestrianModel.calculateDistanceMatrices(pedestrianSet);
        pedestrianModel.calculateNeartestNeighbors(pedestrianSet);

        TEST_CHECK(pedestrianModel.getNearestNeighbors().at(0).second == -1);
        TEST_CHECK(pedestrianModel.getNearestNeighbors().at(1).second == 0);
        TEST_CHECK(pedestrianModel.getNearestNeighbors().at(2).second == 1);
        
    }

    void ModelCalculatesCorrectPropulsion(void) {
        CalmPedestrianSet pedSet;
        CalmPedestrianModel pedModel;
        CalmGoals goals;
        AirplaneObstacleSet obs;
        PointMapLoader loader;

        obs.initialize(loader.LoadMap("../../Maps/obstacle_maps/a320_144_obstacles/a320_144_obstacles.omap"));
        pedSet.configure(CONFIG_MAP{{"mass", "1.000000"}, {"reaction_time", "0.400000"}, {"desired_speed", "1.000000"}});
        pedSet.initialize(CALM_PEDESTRIAN_ENTITY_SET);
        goals.configure(CONFIG_MAP{{"endGoalType", "exits"}, {"pathFinding", "Disembark"}, {"diagonalCost", "2.0"}, {"goalRange", "0.05"}});
        goals.initialize(obs, pedSet);
        goals.updatePedestrianGoals(obs, pedSet);

        pedModel.initialize(pedSet, obs, goals);
        pedModel.update(pedSet, obs, goals, 0);

        for(int i = 0; i < pedSet.getNumPedestrians(); i++) {
            TEST_CHECK(pedModel.getPropulsionForces().at(i).axis[0] == 0);
            TEST_CHECK(pedModel.getPropulsionForces().at(i).axis[1] == 0);
        }
    }
}


#define calm_pedestrian_model_tests \
{"CALM_PEDESTRIAN_MODEL: Model Returns Correct Distance", \ 
    Calm_Pedestrian_Model_TESTS::ModelReturnsCorrectDistanceMatrix}, \
{"CALM_PEDESTRIAN_MODEL: Model Calculates Correct Nearest Neighbor", \ 
    Calm_Pedestrian_Model_TESTS::ModelCalculatesCorrectNearestNeighbor}, \  
{"CALM_PEDESTRIAN_MODEL: Model Calculates Correct Propulsion", \ 
    Calm_Pedestrian_Model_TESTS::ModelCalculatesCorrectPropulsion} \  

    