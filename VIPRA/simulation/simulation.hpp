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
        Clock clock;
        
    public:
        Simulation();
        Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel);
        void run();

        void setOutputCriterionChecker(
            OutputCriterionChecker* outputCriterionChecker);
        int* getTimestep();
        void printDataDELETETHIS();
};

#endif
