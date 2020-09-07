#ifndef SIMULATION_OUTPUT_HANDLER_HPP
#define SIMULATION_OUTPUT_HANDLER_HPP

#include "output_data_writer.hpp"
#include "../entity_sets/pedestrian_set.hpp"

class SimulationOutputHandler 
{
    public:
        virtual ~SimulationOutputHandler() = default;

        virtual void setOutputDataWriter(
            OutputDataWriter* outputDataWriter) = 0;
        virtual void setPedestrianSet(PedestrianSet* pedestrianSet) = 0;
        virtual bool isOutputCriterionMet() = 0;
        virtual void writeData() = 0;
};

#endif