#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include "pedestrian_set.hpp"
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

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
        std::vector<FLOATING_NUMBER> propulsionForces;
        std::vector<FLOATING_NUMBER> repulsionForces;
        std::vector<int> nearestNeighbors;

    public:
        CalmPedestrianSet();
        
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

        std::vector<FLOATING_NUMBER>* getMasses();
        std::vector<FLOATING_NUMBER>* getReactionTimes();
        std::vector<FLOATING_NUMBER>* getDesiredSpeeds();
        std::vector<FLOATING_NUMBER>* getPropulsionForces();
        std::vector<FLOATING_NUMBER>* getRepulsionForces();
        std::vector<int>* getNearestNeighbors();

        void setMasses(std::vector<FLOATING_NUMBER> massesKg);
        void setReactionTimes(std::vector<FLOATING_NUMBER> reactionTimes);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER> desiredSpeeds);
        void setPropulsionForces(std::vector<FLOATING_NUMBER> propulsionForces);
        void setRepulsionForces(std::vector<FLOATING_NUMBER> repulsionForces);
        void setNearestNeighbors(std::vector<int> nearestNeighbors);
};

#endif
