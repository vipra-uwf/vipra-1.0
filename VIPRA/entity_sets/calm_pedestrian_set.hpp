#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <utility>
#include <string>
#include "pedestrian_set.hpp"
#include "../definitions/movement_definitions.hpp"

class CalmPedestrianSet: public PedestrianSet
{
    private:
        int numPedestrians;
    
        std::vector<Dimensions> pedestrianCoordinates;
        std::vector<Dimensions> goalCoordinates;
        std::vector<Dimensions> velocities;

        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;
        std::vector<FLOATING_NUMBER> reactionTimes;
        std::vector<FLOATING_NUMBER> desiredSpeeds;
        std::vector<Dimensions> propulsionForces;
        std::vector<std::pair<std::string, int>> nearestNeighbors;
        std::vector<int> nearestPedNeighbors;
        std::vector<FLOATING_NUMBER> priorities;
        std::vector<MovementDefinitions> movementStates;
        std::vector<int> startingAisles;

    public:
        CalmPedestrianSet();

        virtual void configure(CONFIG_MAP* configMap);
        
        virtual void removePedestrian(int pedestrianIndex);

        virtual int getNumPedestrians();
        virtual std::vector<Dimensions>* getPedestrianCoordinates();
        virtual std::vector<Dimensions>* getGoalCoordinates();
        virtual std::vector<Dimensions>* getVelocities();
        virtual std::vector<FLOATING_NUMBER>* getSpeeds();

        virtual void setNumPedestrians(int numPedestrians);
        virtual void setPedestrianCoordinates(
				std::vector<Dimensions> coordinates);
        virtual void setGoalCoordinates(
				std::vector<Dimensions> goalCoordinates);
        virtual void setVelocities(
				std::vector<Dimensions> velocities);
        virtual void setSpeeds(
				std::vector<FLOATING_NUMBER> speedsMetersPerSecond);

        // virtual ~CalmPedestrianSet();

        std::vector<FLOATING_NUMBER>* getMasses();
        std::vector<FLOATING_NUMBER>* getReactionTimes();
        std::vector<FLOATING_NUMBER>* getDesiredSpeeds();
        std::vector<Dimensions>* getPropulsionForces();
        std::vector<FLOATING_NUMBER>* getRepulsionForces();
        std::vector<std::pair<std::string, int>>* getNearestNeighbors();
        std::vector<int>* getNearestPedNeighbors();
        std::vector<FLOATING_NUMBER>* getPriorities();
        std::vector<MovementDefinitions>* getMovementStates();
        std::vector<int>* getStartingAisles();

        void setMasses(std::vector<FLOATING_NUMBER> massesKg);
        void setReactionTimes(std::vector<FLOATING_NUMBER> reactionTimes);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER> desiredSpeeds);
        void setPropulsionForces(std::vector<Dimensions> propulsionForces);
        void setRepulsionForces(std::vector<FLOATING_NUMBER> repulsionForces);
        void setNearestNeighbors(
          std::vector<std::pair<std::string, int>> nearestNeighbors);
        void setNearestPedNeighbors(std::vector<int>);
        void setPriorities(std::vector<FLOATING_NUMBER> priorities);
        void setMovementStates(std::vector<MovementDefinitions> movementStates);
        void setStartingAisles(std::vector<int> startingAisles);
};

#endif
