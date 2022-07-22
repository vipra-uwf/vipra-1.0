#include "timestep_console_logger.hpp"

void TimestepConsoleLogger::configure(CONFIG_MAP *configMap)
{
    setOutputWritingFrequency(std::stoi((*configMap)["outputFrequency"]));
    std::cout << "OUTPUT FREQ: " << std::to_string(this->frequency) << '\n';
}

void TimestepConsoleLogger::setOutputDataWriter(
    OutputDataWriter *outputDataWriter)
{
    this->outputDataWriter = outputDataWriter;
}

void TimestepConsoleLogger::setPedestrianSet(PedestrianSet *pedestrianSet)
{
    this->pedestrianSet = pedestrianSet;
}

void TimestepConsoleLogger::setSimulation(Simulation *simulation)
{
    this->simulation = simulation;
    setTimestep(this->simulation->getTimestep());
}

bool TimestepConsoleLogger::isOutputCriterionMet()
{
    return *this->timestep % this->frequency == 0;
}

void TimestepConsoleLogger::writeToDocument() 
{
    printPedestrianData();
}

void TimestepConsoleLogger::setTimestep(int *timestep)
{
    this->timestep = timestep;
}

void TimestepConsoleLogger::setOutputWritingFrequency(int frequency)
{
    this->frequency = frequency;
}

void TimestepConsoleLogger::printPedestrianData()
{
}