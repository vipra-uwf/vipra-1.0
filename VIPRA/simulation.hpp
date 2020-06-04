#ifndef SIMULATION_HPP
#define SIMULATION_HPP

//#include <vector>
#include <iostream>
//#include <fstream>
#include <string>

#include "rapidxml-1.13/rapidxml.hpp"
#include "input_data_loader.hpp"
#include "pedestrian_dynamics_model.hpp"
#include "data.hpp" //REMOVE ME WHEN PRINTDATADELETETHIS() IS REMOVED

class Simulation
{
    public:
        Simulation();
        Simulation(PedestrianDynamicsModel*);
        void run();

        void printDataDELETETHIS();

    private:
        PedestrianDynamicsModel* pedestrianDynamicsModel;
};

#endif
