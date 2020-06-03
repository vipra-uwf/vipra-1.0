#include "type_definitions.hpp"
#include <vector>

class ObstacleSet{
    public:
        ObstacleSet();
        void addObstacle(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate);
        int getNumObstacles();
        FLOATING_NUMBER getXCoordinate(int i);
        FLOATING_NUMBER getYCoordinate(int i);
    private:
        int numObstacles;
        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;
};