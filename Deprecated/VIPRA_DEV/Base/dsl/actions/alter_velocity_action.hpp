//
// Created by joe on 12/7/21.
//

#ifndef VIPRA_ALTER_VELOCITY_ACTION_HPP
#define VIPRA_ALTER_VELOCITY_ACTION_HPP


#include "action.hpp"

typedef enum { FASTER, SLOWER } ALTER_DIRECTION;

class AlterVelocityAction : public Action {
    public:
        AlterVelocityAction(SimulationContext *simulationContext, ALTER_DIRECTION alterDirection,
                            FLOATING_NUMBER factor);
        void performAction(int pedestrianIndex) override;
        void initialize() override;

private:
        Dimensions computeAlteredDimensions(Dimensions originalDimensions);
        std::vector<bool> actionAppliedStatus;
        ALTER_DIRECTION alterDirection;
        FLOATING_NUMBER factor;

};


#endif //VIPRA_ALTER_VELOCITY_ACTION_HPP
