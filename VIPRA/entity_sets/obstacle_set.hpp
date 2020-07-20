#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>

#include "../type_definitions.hpp"
#include "../dimensions.hpp"

//TODO this class should probably be derived - alex
class ObstacleSet
{
    private:
        int numObstacles;
		//TODO this should be const then delete numPed setter and getter - alex
        int numDimensions = 2;
		//what if the user doesn't want to use single point coordinates?
        std::vector<Dimensions> obstacleCoordinates;

    public:
        ObstacleSet();
        
        int getNumObstacles();
        int getNumDimensions();
        std::vector<Dimensions>* getObstacleCoordinates();

        void setNumObstacles(int numObstacles); 
        void setNumDimensions(int numDimensions);
        void setObstacleCoordinates(std::vector<Dimensions> coordinates);
};

#endif
