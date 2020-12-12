#ifndef DIMENSIONS
#define DIMENSIONS

#include <vector>

#include "type_definitions.hpp"

struct Dimensions
{
    // x = 0, y = 1, z = 2, etc..
    std::vector<FLOATING_NUMBER> coordinates;
};

#endif