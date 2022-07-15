#ifndef TIMESTEP_OUTPUT_HANDLER_HPP 
#define TIMESTEP_OUTPUT_HANDLER_HPP

#include "../simulation_output_handler.hpp"

class TimestepOutputHandler: public SimulationOutputHandler
{    
    private: 
        int frequency;
        int* timestep;
        int timestepID;
        OutputDataWriter* outputDataWriter;
        PedestrianSet* pedestrianSet;
        Simulation* simulation;
        void setTimestep(int* timestep);
        void setOutputWritingFrequency(int frequency);

    public:
        virtual void configure(CONFIG_MAP* configMap);
        virtual void setOutputDataWriter(OutputDataWriter* outputDataWriter);
        virtual void setPedestrianSet(PedestrianSet* pedestrianSet);
        virtual void setSimulation(Simulation* simulation);
        virtual bool isOutputCriterionMet();
        virtual void writeToDocument();
};

#endif
 