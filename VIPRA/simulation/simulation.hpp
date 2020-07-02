#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <iostream> 

#include "../rapidxml/rapidxml.hpp"
#include "../readers/input_data_loader.hpp" //TODO may be able to remove -- is data *always* loaded outside of the simulation?
#include "../writers/output_criterion_checker.hpp"
#include "../models/pedestrian_dynamics_model.hpp"
#include "data.hpp" //TODO REMOVE ME WHEN PRINTDATADELETETHIS() IS REMOVED
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
        //TODO will be removed once debugger segfault is resolved
        void printDataDELETETHIS();


};

#endif
