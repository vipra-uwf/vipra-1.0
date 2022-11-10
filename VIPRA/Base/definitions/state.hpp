#ifndef STATE_HPP
#define STATE_HPP

#include "type_definitions.hpp"

struct State {

    State(DimVector& velocities, DimVector& pedestrianCoordinates) {
        this->velocities = velocities;
        this->pedestrianCoordinates = pedestrianCoordinates;
    }
    
    DimVector velocities;
    DimVector pedestrianCoordinates;

};

#endif