#include "clock.hpp"

Clock::Clock()
{
    this->simulationElapsedMilliseconds = 0;
}

void Clock::start()
{
    this->realStartTime = std::chrono::system_clock::now(); 
}

void Clock::stop()
{
    this->realEndTime = std::chrono::system_clock::now(); 
}

void Clock::printRealStartTime()
{
    std::time_t time = std::chrono::system_clock::to_time_t(this->realStartTime);
    std::cout << "computation started: " << std::ctime(&time);
}

void Clock::calculateRealElapsedSeconds()
{
    this->realElapsedSeconds = this->realEndTime - this->realStartTime;
}

void Clock::printRealDuration()
{
    calculateRealElapsedSeconds();
    std::cout << "elapsed time: " << this->realElapsedSeconds.count() << "s\n"; 
}

void Clock::printRealEndTime()
{
    std::time_t time = std::chrono::system_clock::to_time_t(this->realEndTime);
    std::cout << "computation finished: " << std::ctime(&time);
}

void Clock::addSimulationTimeMilliseconds(unsigned long milliseconds)
{
    this->simulationElapsedMilliseconds += milliseconds;
}

void Clock::printSimulationDuration()
{
    
    std::cout << "Simulation duration: " 
        << float(this->simulationElapsedMilliseconds)/1000
        << "s"
        << std::endl;
}