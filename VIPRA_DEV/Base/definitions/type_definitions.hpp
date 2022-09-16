
#include "../_pch/pch.hpp"

typedef float FLOATING_NUMBER;

struct Dimensions {
  FLOATING_NUMBER x, y, z;
};

typedef std::vector<Dimensions> DimVector;

typedef std::unordered_map<std::string, std::string> CONFIG_MAP;

typedef std::unordered_map<std::string, DimVector> ENTITY_SET;