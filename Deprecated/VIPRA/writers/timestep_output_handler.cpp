#include "timestep_output_handler.hpp"

void TimestepOutputHandler::configure(CONFIG_MAP* configMap)
{
    setOutputWritingFrequency(std::stoi((*configMap)["outputFrequency"]));
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

void TimestepOutputHandler::setSimulation(Simulation* simulation)
{
    this->simulation = simulation;
    setTimestep(this->simulation->getTimestep());
}

bool TimestepOutputHandler::isOutputCriterionMet()
{
    if (*this->timestep % this->frequency == 0) {
        this->timestepID = *this->timestep / this->frequency;
        return true;
    }
    return false;
}

void TimestepOutputHandler::writeToDocument()
{
    this->outputDataWriter->addFloatValue(
        "NEW_TIMESTEP", this->timestepID);
    
    for(int i = 0; i < this->pedestrianSet->getNumPedestrians(); ++i)
    {
        this->outputDataWriter->addFloatValue(
            "x", (*this->pedestrianSet->getPedestrianCoordinates()).
            at(i).coordinates[0]);
        this->outputDataWriter->addFloatValue(
            "y", (*this->pedestrianSet->getPedestrianCoordinates()).
            at(i).coordinates[1]);
    }
}

void TimestepOutputHandler::setTimestep(int* timestep)
{
    this->timestep = timestep;
}

void TimestepOutputHandler::setOutputWritingFrequency(int frequency)
{
    this->frequency = frequency;
}