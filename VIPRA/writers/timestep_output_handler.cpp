#include "timestep_output_handler.hpp"

void TimestepOutputHandler::setOutputWritingFrequency(int frequency)
{
    this->frequency = frequency;
}

void TimestepOutputHandler::setTimestep(int* timestep)
{
    this->timestep = timestep;
}

void TimestepOutputHandler::setOutputDataWriter(
    OutputDataWriter* outputDataWriter)
{
    this->outputDataWriter = outputDataWriter;
}

void TimestepOutputHandler::setPedestrianSet(PedestrianSet* pedestrianSet)
{
    this->pedestrianSet = pedestrianSet;
}

bool TimestepOutputHandler::isOutputCriterionMet()
{
    return *this->timestep % this->frequency == 0;
}

void TimestepOutputHandler::writeData()
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
