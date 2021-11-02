#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <iostream> 

#include "../rapidxml/rapidxml.hpp" // TODO figure out why this is here
#include "../writers/simulation_output_handler.hpp"
#include "../models/pedestrian_dynamics_model.hpp"
#include "../models/human_behavior_model.hpp"
#include "clock.hpp"

#include "../entity_sets/calm_pedestrian_set.hpp" // TODO when printDataDELETETHIS is deleted

class SimulationOutputHandler; // forward declaring 

class Simulation
{
    private:
        int timestep;
        FLOATING_NUMBER timestep_size;
        PedestrianDynamicsModel* pedestrianDynamicsModel;
        HumanBehaviorModel* humanBehaviorModel;
        SimulationOutputHandler* simulationOutputHandler;
        Clock clock;
        Data* data;
        
    public:
        Simulation();
        Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel, HumanBehaviorModel *humanBehaviorModel);
        void setData(Data* data);
        void initialize();
        void run();

        void setSimulationOutputHandler(
            SimulationOutputHandler* simulationOutputHandler);
        int* getTimestep();
        PedestrianDynamicsModel* getPedestrianDynamicsModel();
        void printDataDELETETHIS();
        void testGoalClassDELETETHIS();
};

#endif
