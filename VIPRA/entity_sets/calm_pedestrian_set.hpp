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

        void initializeSpeeds();
        void initializeGoals();
        void initializeVelocities();
        void initializePropulsionForces();
        void initializeRepulsionForces();
        void initializeNearestNeighbors();


    public:
        CalmPedestrianSet();

        virtual void initializeValues();
        virtual void pedestrianGoalMet(int pedestrianIndex);

        virtual int getNumPedestrians();
        virtual std::vector<Dimensions>* getPedestrianCoordinates();
        virtual std::vector<Dimensions>* getGoalCoordinates();
        virtual std::vector<Dimensions>* getVelocities();
        virtual std::vector<FLOATING_NUMBER>* getSpeeds();

        // TODO these should not be virtual - alex
        virtual std::vector<FLOATING_NUMBER>* getMasses();
        virtual std::vector<FLOATING_NUMBER>* getReactionTimes();
        virtual std::vector<FLOATING_NUMBER>* getDesiredSpeeds();
        virtual std::vector<FLOATING_NUMBER>* getPropulsionForces();
        virtual std::vector<FLOATING_NUMBER>* getRepulsionForces();
        virtual std::vector<int>* getNearestNeighbors();

        virtual void setNumPedestrians(int numPedestrians);
        virtual void setPedestrianCoordinates(
        std::vector<Dimensions> coordinates);
        virtual void setGoalCoordinates(
        std::vector<Dimensions> goalCoordinates);
        virtual void setVelocities(
        std::vector<Dimensions> velocities);
        virtual void setSpeeds(
        std::vector<FLOATING_NUMBER> speedsMetersPerSecond);

        //TODO these shouldnt be virtual - alex
        virtual void setMasses(std::vector<FLOATING_NUMBER> massesKg);
        virtual void setReactionTimes(
        std::vector<FLOATING_NUMBER> reactionTimes);
        virtual void setDesiredSpeeds(
        std::vector<FLOATING_NUMBER> desiredSpeeds);
        virtual void setPropulsionForces(
        std::vector<FLOATING_NUMBER> propulsionForces);
        virtual void setRepulsionForces(
        std::vector<FLOATING_NUMBER> repulsionForces);

        //TODO should probably make this plural - alex	
        virtual void setNearestNeighbors(std::vector<int> nearestNeighbors);
};

#endif
