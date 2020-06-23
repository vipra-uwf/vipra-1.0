#include "timer.hpp"

Timer::Timer()
{
    
}

void Timer::start()
{
    this->startTime = std::chrono::system_clock::now(); 
}

void Timer::stop()
{
    this->endTime = std::chrono::system_clock::now(); 
}

void Timer::printStartTime()
{
    std::time_t time = std::chrono::system_clock::to_time_t(this->startTime);
    std::cout << "computation started: " << std::ctime(&time) << std::endl;
}

void Timer::calculateElapsedSeconds()
{
    this->elapsedSeconds = this->endTime - this->startTime;
}

void Timer::printDuration()
{
    calculateElapsedSeconds();
    std::cout << "elapsed time: " << this->elapsedSeconds.count() << "s\n"; 
}

void Timer::printEndTime()
{
    std::time_t time = std::chrono::system_clock::to_time_t(this->endTime);
    std::cout << "computation finished: " << std::ctime(&time) << std::endl;
}