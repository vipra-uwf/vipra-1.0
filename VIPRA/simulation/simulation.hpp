#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <iostream> 

#include "../rapidxml/rapidxml.hpp"
#include "../writers/output_criterion_checker.hpp"
#include "../models/pedestrian_dynamics_model.hpp"
#include "clock.hpp"

class Simulation
{
    private:
        int timestep;
        PedestrianDynamicsModel* pedestrianDynamicsModel;
        OutputCriterionChecker* outputCriterionChecker;

    public:
        Simulation();
        Simulation(PedestrianDynamicsModel*);
        void run();

        void setOutputCriterionChecker(OutputCriterionChecker*);
        int* getTimestep();


};

#endif
