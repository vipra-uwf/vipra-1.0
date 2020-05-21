#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include <vector>
#include <utility>

class InputDataLoader
{
    public:
        virtual void readData() = 0;
       
        virtual std::vector<double> getXPedestrianCoordinates() = 0;
        virtual std::vector<double> getYPedestrianCoordinates() = 0;

        virtual std::vector<double> getXObstacleCoordinates() = 0;
        virtual std::vector<double> getYObstacleCoordinates() = 0; 
};

#endif
