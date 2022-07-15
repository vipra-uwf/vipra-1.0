#ifndef AIRPLANE_OBSTACLE_SET
#define AIRPLANE_OBSTACLE_SET

#include "../Interfaces/obstacleset/obstacle_set.hpp"

class AirplaneObstacleSet: public ObstacleSet 
{
   private:
        int numObstacles;
        int numAisles;
        std::vector<Dimensions> obstacleCoordinates;
        std::vector<FLOATING_NUMBER> aisles; //should i make these two one vector of pairs? or a vector of dimensions? -EL
        std::vector<FLOATING_NUMBER> aislesSize;

        std::vector<Dimensions> exits;

    public:
        AirplaneObstacleSet();
       
        virtual void configure(CONFIG_MAP* configMap);
        virtual int getNumObstacles();
        virtual std::vector<Dimensions>* getObstacleCoordinates();
        virtual void setNumObstacles(int numObstacles);
        virtual void setObstacleCoordinates(
            std::vector<Dimensions> coordinates);

        int getNumAisles();
        std::vector<FLOATING_NUMBER>* getAisles();
        std::vector<FLOATING_NUMBER>* getAislesSize();

        void setExits(const std::vector<Dimensions>& exits);
        const std::vector<Dimensions>& getExits();

        void setNumAisles(int numAisles);
        void setAisles(std::vector<FLOATING_NUMBER>);
        void setAislesSize(std::vector<FLOATING_NUMBER>);

};

#endif