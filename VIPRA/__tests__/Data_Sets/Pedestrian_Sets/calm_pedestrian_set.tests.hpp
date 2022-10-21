#pragma once

#include "./../../acutest/acutest.h"

#include "./../../../Base/definitions/type_definitions.hpp"
#include "./../../../../Modules/PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"

namespace Calm_Pedestrian_Set_TESTS {

    void
    LoadProperValuesInPedestrianSet(void) {
    CalmPedestrianSet pedestrianSet;
    size_t numPedestrians = 100;

    pedestrianSet.initialize(numPedestrians);

    TEST_CHECK(pedestrianSet.getIds().size() == numPedestrians);
    TEST_CHECK(pedestrianSet.getVelocities().size() == numPedestrians);
    TEST_CHECK(pedestrianSet.getSpeeds().size() == numPedestrians);
    TEST_CHECK(pedestrianSet.getMasses().size() == numPedestrians);
    TEST_CHECK(pedestrianSet.getReactionTimes().size() == numPedestrians);
    TEST_CHECK(pedestrianSet.getDesiredSpeeds().size() == numPedestrians);
    TEST_CHECK(pedestrianSet.getShoulderLengths().size() == numPedestrians);


    }
}

#define calm_pedestrian_set_tests                                                          \
  {"CALM_PEDESTRIAN_SET: Load Proper Values In Pedestrian Set",                                      \
   Calm_Pedestrian_Set_TESTS::LoadProperValuesInPedestrianSet}                                        \
  \
