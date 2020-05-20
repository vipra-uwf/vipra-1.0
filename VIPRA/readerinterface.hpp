#ifndef READERINTERFACE_HPP
#define READERINTERFACE_HPP

#include <vector>
#include <utility>

class ReaderInterface
{
    public:
        virtual void readData() = 0;
        virtual std::vector<std::string> getPassengerTypes() = 0;
        virtual std::vector<std::pair<double, double>> getPassengerCoordinates() = 0;
        virtual std::vector<std::pair<double, double>> getObstacleCoordinates() = 0;
};

#endif
