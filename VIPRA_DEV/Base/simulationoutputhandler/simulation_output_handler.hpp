#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "../outputdatawriter/output_data_writer.hpp"
#include "../simulation/simulation/simulation.hpp"
#include "../definitions/type_definitions.hpp"

#include "../../Interfaces/pedestrianset/pedestrian_set.hpp"

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