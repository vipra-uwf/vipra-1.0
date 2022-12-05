//
// Created by joe on 12/10/21.
//

#ifndef VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
#define VIPRA_EXACTLY_N_RANDOM_SELECTOR_H


#include "selector.hpp"

class ExactlyNRandomSelector: public Selector
{
    public:
        ExactlyNRandomSelector(SimulationContext *simulationContext, int count, unsigned int seed);
        void initialize() override;

    protected:
        bool select(int pedestrianIndex, const ObstacleSet& obstacleSet, const Goals& goals, const PedestrianSet& pedestrianSet) override;

    private:
        std::vector<int> selectedPedestrianIds;
        int count;
        void selectPedestrianIds(const PedestrianSet& pedestrianSet);
};


#endif //VIPRA_EXACTLY_N_RANDOM_SELECTOR_H
