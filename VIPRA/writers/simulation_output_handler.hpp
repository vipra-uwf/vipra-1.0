#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "output_data_writer.hpp"
#include "../simulation/simulation.hpp"
#include "../entity_sets/pedestrian_set.hpp"
#include "../type_definitions.hpp"

class Simulation; // forward declaring

class SimulationOutputHandler 
{
    public:
        virtual ~SimulationOutputHandler() = default;

        virtual void configure(CONFIG_MAP* configMap) = 0;
        virtual void setOutputDataWriter(
            OutputDataWriter* outputDataWriter) = 0;
        virtual void setPedestrianSet(PedestrianSet* pedestrianSet) = 0;
        virtual void setSimulation(Simulation* simulation) = 0;
        virtual bool isOutputCriterionMet() = 0;
        virtual void writeToDocument() = 0;
};

#endif