#include "acutest/acutest.h"

#include "./IO/input_data_loader/tests.hpp"
#include "./IO/output_data_writer/tests.hpp"

#include "./Data_Sets/Obstacle_Sets/tests.hpp"
#include "./Data_Sets/Pedestrian_Sets/tests.hpp"

#include "./Models/Behavior_Model/tests.hpp"
#include "./Models/Pedestrian_Model/tests.hpp"

#include "./Goals/tests.hpp"

TEST_LIST = {INPUT_DATA_LOADER_TESTS, {NULL, NULL}};