#include "output_timestep_checker.hpp"

void OutputTimestepChecker::setOutputWritingFrequency(int frequency)
{
    this->frequency = frequency;
}

void OutputTimestepChecker::setTimestep(int* timestep)
{
    this->timestep = timestep;
}

void OutputTimestepChecker::setOutputDataWriter(
    OutputDataWriter* outputDataWriter)
{
    this->outputDataWriter = outputDataWriter;
}

void OutputTimestepChecker::setPedestrianSet(PedestrianSet* pedestrianSet)
{
    this->pedestrianSet = pedestrianSet;
}

bool OutputTimestepChecker::isOutputCriterionMet()
{
    return *this->timestep % this->frequency == 0;
}

void OutputTimestepChecker::writeData()
{
    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        this->outputDataWriter->writeFloatData(
            "x", (*this->pedestrianSet->getPedestrianCoordinates()).
            at(i).coordinates[0]);
        this->outputDataWriter->writeFloatData(
            "y", (*this->pedestrianSet->getPedestrianCoordinates()).
            at(i).coordinates[1]);
    }
}
