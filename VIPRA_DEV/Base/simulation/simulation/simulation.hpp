#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <iostream> 

#include "../clock/clock.hpp"
#include "../../simulationoutputhandler/simulation_output_handler.hpp"
#include "../../humanbehavior/human_behavior_model.hpp"

#include "../../../Interfaces/pedestrianmodel/pedestrian_dynamics_model.hpp"

#include "../../../calm_pedestrian_model/calm_pedestrian_model.hpp"

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
        //Simulation(PedestrianDynamicsModel* pedestrianDynamicsModel, HumanBehaviorModel *humanBehaviorModel);
        void configure(CONFIG_MAP* config);
        void setData(Data* data);
        void setPedestrianModel(PedestrianDynamicsModel* pedestrianModel);
        void setHumanBehaviorModel(HumanBehaviorModel* behaviorModel);
        //void initialize();
        void run();

        void setSimulationOutputHandler(
            SimulationOutputHandler* simulationOutputHandler);
        int* getTimestep();
        PedestrianDynamicsModel* getPedestrianDynamicsModel();


        void printDataDELETETHIS();
};

#endif
