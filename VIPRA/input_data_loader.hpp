#ifndef INPUTDATALOADER_HPP
#define INPUTDATALOADER_HPP

#include <vector>
#include <utility>

class InputDataLoader
{
    public:
        virtual void readData() = 0;
        virtual std::vector<std::pair<double, double>> getPassengerCoordinates() = 0;
        virtual std::vector<std::pair<double, double>> getObstacleCoordinates() = 0;
};

#endif
