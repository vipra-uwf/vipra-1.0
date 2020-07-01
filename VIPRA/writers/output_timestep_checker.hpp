#ifndef OUTPUT_TIMESTEP_CHECKER_HPP 
#define OUTPUT_TIMESTEP_CHECKER_HPP 

#include "output_criterion_checker.hpp"

class OutputTimestepChecker: public OutputCriterionChecker
{    
    private: 
        int frequency;
        int* timestep;
        PedestrianSet* pedestrianSet;
        OutputDataWriter* outputDataWriter;

    public:
        void setTimestep(int*);
        void setOutputWritingFrequency(int);
        virtual void setOutputDataWriter(OutputDataWriter*);
        virtual void setPedestrianSet(PedestrianSet*);
        virtual bool isOutputCriterionMet();
        virtual void writeData();
};

#endif
 