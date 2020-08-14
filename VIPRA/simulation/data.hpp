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
		
        std::unordered_map<std::string, FLOATING_NUMBER>* simulationParams; 
    
    public:
        Data();

        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();
		std::unordered_map<std::string, FLOATING_NUMBER>* getSimulationParams();
        
		void setPedestrianSet(PedestrianSet* pedestrianSet);
		void setObstacleSet(ObstacleSet* obstacleSet);	
		void setSimulationParams(
            std::unordered_map<std::string, FLOATING_NUMBER>* simulationParams); 
};

#endif
