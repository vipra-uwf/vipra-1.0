#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "../../_pch/pch.hpp"

#include "../../definitions/type_definitions.hpp"

class Clock
{
    private:
        std::chrono::time_point<std::chrono::system_clock> realStartTime;
        std::chrono::time_point<std::chrono::system_clock> realEndTime;
        std::chrono::time_point<std::chrono::system_clock> simulationEndTime;
        std::chrono::duration<double> realElapsedSeconds;
        void calculateRealElapsedSeconds();
        unsigned long simulationElapsedMs;

    public:
        Clock();
        void start();
        void stop();
        void printRealStartTime(); 
        void printRealDuration();
        void printRealEndTime();
        void addSimulationTimeMs(unsigned long milliseconds);
        void printSimulationDuration();

        void configure(CONFIG_MAP* config);
};

#endif