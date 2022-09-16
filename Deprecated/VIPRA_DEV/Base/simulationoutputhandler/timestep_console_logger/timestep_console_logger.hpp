#ifndef TIMESTEP_CONSOLE_LOGGER_HPP
#define TIMESTEP_CONSOLE_LOGGER_HPP

#include "../simulation_output_handler.hpp"

class TimestepConsoleLogger: public SimulationOutputHandler
{    
    private: 
        int frequency;
        int* timestep;
        OutputDataWriter* outputDataWriter;
        PedestrianSet* pedestrianSet;
        Simulation* simulation;
        void setTimestep(int* timestep);
        void setOutputWritingFrequency(int frequency);
        void printPedestrianData();
        void printAndTestGoals();

    public:
        virtual void configure(CONFIG_MAP* configMap);
        virtual void setOutputDataWriter(OutputDataWriter* outputDataWriter);
        virtual void setPedestrianSet(PedestrianSet* pedestrianSet);
        virtual void setSimulation(Simulation* simulation);
        virtual bool isOutputCriterionMet();
        virtual void writeToDocument();
};

#endif