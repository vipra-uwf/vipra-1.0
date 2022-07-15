#ifndef DATA_HPP
#define DATA_HPP

#include <unordered_map>
#include <string>

#include "../../../Interfaces/pedestrianset/pedestrian_set.hpp"
#include "../../../Interfaces/obstacleset/obstacle_set.hpp"

class Data
{
    private:
        PedestrianSet* pedestrianSet;
        ObstacleSet* obstacleSet;
    
    public:
        Data();
        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();
        
        void configure(CONFIG_MAP* config);
		void setPedestrianSet(PedestrianSet* pedestrianSet);
		void setObstacleSet(ObstacleSet* obstacleSet);	
};

#endif
