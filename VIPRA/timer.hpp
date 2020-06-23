#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream> 
#include <chrono> 
#include <ctime> 

class Timer
{
    private:
        std::chrono::time_point<std::chrono::system_clock> startTime;
        std::chrono::time_point<std::chrono::system_clock> endTime;
        std::chrono::duration<double> elapsedSeconds;
        void calculateElapsedSeconds();
    public:
        Timer();
        void start();
        void stop();
        void printStartTime(); 
        void printDuration();
        void printEndTime();    
};

#endif