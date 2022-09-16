#ifndef DIMENSIONS
#define DIMENSIONS

#include "../_pch/pch.hpp"

#include "type_definitions.hpp"

// struct Dimensions
// {
//     // x = 0, y = 1, z = 2, etc..
//     std::vector<FLOATING_NUMBER> coordinates;

//     explicit Dimensions(const std::vector<FLOATING_NUMBER>& dims) : coordinates(dims){}
// };

typedef std::vector<FLOATING_NUMBER> Dimensions;
typedef std::vector<Dimensions> DimsVector;


#endif