#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream> 
#include <chrono> 
#include <ctime> 

class Timer
{
    private:
        std::chrono::time_point<std::chrono::system_clock> realStartTime;
        std::chrono::time_point<std::chrono::system_clock> realEndTime;
        std::chrono::time_point<std::chrono::system_clock> simulationEndTime;
        std::chrono::duration<double> realElapsedSeconds;
        void calculateRealElapsedSeconds();
        unsigned long simulationElapsedMilliseconds;

    public:
        Timer();
        void start();
        void stop();
        void printRealStartTime(); 
        void printRealDuration();
        void printRealEndTime();
        void addSimulationTimeMilliseconds(unsigned long milliseconds);
        void printSimulationDuration();
};

#endif