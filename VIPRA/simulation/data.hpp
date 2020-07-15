#ifndef DATA_HPP
#define DATA_HPP

#include <unordered_map>
#include <string>

#include "../entity_sets/pedestrian_set.hpp"
#include "../entity_sets/obstacle_set.hpp"

// TODO .. we should probably make this into a virtual class..
// the derived class would be CalmData -- Alex
class Data
{
    private:
        PedestrianSet* pedestrianSet;
        ObstacleSet obstacleSet;
		std::unordered_map<std::string, FLOATING_NUMBER> hashMapData; //rename to match responsibility
    public:
        Data();

        PedestrianSet* getPedestrianSet();
        ObstacleSet* getObstacleSet();
		std::unordered_map<std::string, FLOATING_NUMBER>* getHashMapData();
        
		void setPedestrianSet(PedestrianSet*);
		void setHashMapData(std::unordered_map<std::string, FLOATING_NUMBER>); //rename same as above
};

#endif
