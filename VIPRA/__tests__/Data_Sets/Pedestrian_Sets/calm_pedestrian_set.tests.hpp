#pragma once

#include "./../../acutest/acutest.h"

#include "./../../../../Modules/PedestrianSet/calm_pedestrian_set/calm_pedestrian_set.hpp"
#include "definitions/type_definitions.hpp"

namespace Calm_Pedestrian_Set_TESTS {

void
LoadProperValuesInPedestrianSet(void) {
  CalmPedestrianSet pedestrianSet;
  size_t            numPedestrians = 3;

  DimVector  pedestrianCoords = {{8, 5}, {4, 2}, {0, 5}};
  ENTITY_SET pedestrians = {{"pedestrians", pedestrianCoords}};

  pedestrianSet.initialize(pedestrians);

  TEST_CHECK(pedestrianSet.getIds().size() == numPedestrians);
  TEST_CHECK(pedestrianSet.getVelocities().size() == numPedestrians);
  TEST_CHECK(pedestrianSet.getSpeeds().size() == numPedestrians);
  TEST_CHECK(pedestrianSet.getMasses().size() == numPedestrians);
  TEST_CHECK(pedestrianSet.getReactionTimes().size() == numPedestrians);
  TEST_CHECK(pedestrianSet.getDesiredSpeeds().size() == numPedestrians);
  TEST_CHECK(pedestrianSet.getShoulderLengths().size() == numPedestrians);
}
}  // namespace Calm_Pedestrian_Set_TESTS

#define calm_pedestrian_set_tests                                                                            \
  {                                                                                                          \
    "CALM_PEDESTRIAN_SET: Load Proper Values In Pedestrian Set",                                             \
        Calm_Pedestrian_Set_TESTS::LoadProperValuesInPedestrianSet                                           \
  }
\
