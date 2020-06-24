#include "timer.hpp"

Timer::Timer()
{
    this->simulationElapsedMilliseconds = 0;
}

void Timer::start()
{
    this->realStartTime = std::chrono::system_clock::now(); 
}

void Timer::stop()
{
    this->realEndTime = std::chrono::system_clock::now(); 
}

void Timer::printRealStartTime()
{
    std::time_t time = std::chrono::system_clock::to_time_t(this->realStartTime);
    std::cout << "computation started: " << std::ctime(&time);
}

void Timer::calculateRealElapsedSeconds()
{
    this->realElapsedSeconds = this->realEndTime - this->realStartTime;
}

void Timer::printRealDuration()
{
    calculateRealElapsedSeconds();
    std::cout << "elapsed time: " << this->realElapsedSeconds.count() << "s\n"; 
}

void Timer::printRealEndTime()
{
    std::time_t time = std::chrono::system_clock::to_time_t(this->realEndTime);
    std::cout << "computation finished: " << std::ctime(&time);
}

void Timer::addSimulationTimeMilliseconds(unsigned long milliseconds)
{
    this->simulationElapsedMilliseconds += milliseconds;
}

void Timer::printSimulationDuration()
{
    
    std::cout << "Simulation duration: " 
        << float(this->simulationElapsedMilliseconds)/1000
        << "s"
        << std::endl;
}