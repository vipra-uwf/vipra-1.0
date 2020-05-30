#include "type_definitions.hpp"
#include <vector>

class ObstacleSet{
    public:
        ObstacleSet();
        void addObstacle(FLOATING_NUMBER xCoordinate, FLOATING_NUMBER yCoordinate);
        int getNumObstacles();
        std::vector<FLOATING_NUMBER>* getXCoordinates();
        std::vector<FLOATING_NUMBER>* getYCoordinates();
    private:
        int numObstacles;
        std::vector<FLOATING_NUMBER> xCoordinates;
        std::vector<FLOATING_NUMBER> yCoordinates;
};