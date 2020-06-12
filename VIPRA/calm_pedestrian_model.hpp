#ifndef CALM_PEDESTRIAN_MODEL_HPP
#define CALM_PEDESTRIAN_MODEL_HPP

#include <vector>
#include <iostream>
#include <algorithm>

#include "pedestrian_dynamics_model.hpp"
#include "data.hpp"

class CalmPedestrianModel : public PedestrianDynamicsModel
{
    public:

        CalmPedestrianModel();
        void initializeForces();

        virtual void setData(Data* initialData);
        virtual Data* getData();
        virtual void precompute();
        virtual void update();

        virtual void calculatePropulsion();
        virtual void calculateRepulsion();
        
        
        FLOATING_NUMBER calculateDistance(int, int);
        FLOATING_NUMBER calculateBeta(int);

    private:
        Data* data;

        //TODO initialize with 0s using data.pedset.getNumPedestrians()
        std::vector<FLOATING_NUMBER> propulsionForces;
        std::vector<FLOATING_NUMBER> repulsionForces;
        std::vector<int> nearestNeighbors;


        FLOATING_NUMBER desiredSpeed;
        FLOATING_NUMBER reactionTime;


        const FLOATING_NUMBER a = -2.111;
        const FLOATING_NUMBER b = 0.366;
        const FLOATING_NUMBER c = 0.966;
};

#endif
