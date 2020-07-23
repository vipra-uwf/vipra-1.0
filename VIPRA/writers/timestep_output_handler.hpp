#ifndef TIMESTEP_OUTPUT_HANDLER_HPP 
#define TIMESTEP_OUTPUT_HANDLER_HPP

#include "simulation_output_handler.hpp"

class TimestepOutputHandler: public SimulationOutputHandler
{    
    private: 
        int frequency;
        int* timestep;
        PedestrianSet* pedestrianSet;
        OutputDataWriter* outputDataWriter;

    public:
        void setTimestep(int*);
        void setOutputWritingFrequency(int frequency);
        virtual void setOutputDataWriter(OutputDataWriter* outputDataWriter);
        virtual void setPedestrianSet(PedestrianSet* pedestrianSet);
        virtual bool isOutputCriterionMet();
        virtual void writeData();
};

#endif
 