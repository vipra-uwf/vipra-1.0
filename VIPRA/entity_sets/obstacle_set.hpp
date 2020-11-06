#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>

#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class ObstacleSet
{
    private:
        int numObstacles;
        int numAisles;
        std::vector<Dimensions> obstacleCoordinates;
        std::vector<FLOATING_NUMBER> Aisles; //should i make these two one vector of pairs? or a vector of dimensions? -EL
        std::vector<FLOATING_NUMBER> AislesSize;

    public:
        ObstacleSet();
        
        void configure(CONFIG_MAP* configMap);
        int getNumObstacles();
        int getNumAisles();
        std::vector<Dimensions>* getObstacleCoordinates();
        std::vector<FLOATING_NUMBER>* getAisles();
        std::vector<FLOATING_NUMBER>* getAislesSize();
        
        void setNumObstacles(int numObstacles);
        void setNumAisles(int numAisles);
        void setObstacleCoordinates(std::vector<Dimensions> coordinates);
        void setAisles(std::vector<FLOATING_NUMBER>);
        void setAislesSize(std::vector<FLOATING_NUMBER>);
};

#endif
