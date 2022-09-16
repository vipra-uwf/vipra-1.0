#ifndef DATA_HPP
#define DATA_HPP

#include <unordered_map>
#include <string>

#include "../entity_sets/pedestrian_set.hpp"
#include "../entity_sets/obstacle_set.hpp"

class Data
{
    private:
        PedestrianSet* pedestrianSet;
        ObstacleSet* obstacleSet;
		
        SIM_PARAMS* simulationParams; 
    
    public:
        Data();

        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();
		SIM_PARAMS* getSimulationParams();
        
		void setPedestrianSet(PedestrianSet* pedestrianSet);
		void setObstacleSet(ObstacleSet* obstacleSet);	
		void setSimulationParams(SIM_PARAMS* simulationParams); 
};

#endif
