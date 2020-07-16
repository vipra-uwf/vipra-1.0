#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include "pedestrian_set.hpp"
#include "../type_definitions.hpp"
#include "../dimensions.hpp"

class CalmPedestrianSet: public PedestrianSet
{
    private:
        int numPedestrians;
		//TODO this should be const then delete numPed setter and getter - alex
        int numDimensions = 2;

        std::vector<Dimensions> pedestrianCoordinates;
        std::vector<Dimensions> goalCoordinates;
        std::vector<Dimensions> currentVelocities;
        
        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;
        std::vector<FLOATING_NUMBER> reactionTimes;
        std::vector<FLOATING_NUMBER> desiredSpeeds;
        std::vector<FLOATING_NUMBER> propulsionForces;
        std::vector<FLOATING_NUMBER> repulsionForces;
        std::vector<int> nearestNeighbor;
        
        void initializeSpeeds();
        void initializeGoals();
        void initializeVelocities();
        void initializePropulsionForces();
        void initializeRepulsionForces();
        void initializeNearestNeighbors();


    public:
        CalmPedestrianSet();

        virtual void initializeValues();

        virtual int getNumPedestrians();
        virtual int getNumDimensions();
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
        virtual std::vector<int>* getNearestNeighbor();
        
        virtual void setNumPedestrians(int numPedestrians);
        virtual void setNumDimensions(int numDimensions);
        virtual void setPedestrianCoordinates(
				std::vector<Dimensions> coordinates);
        virtual void setGoalCoordinates(
				std::vector<Dimensions> goalCoordinates);
        virtual void setVelocities(
				std::vector<Dimensions> currentVelocities);
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
		virtual void setNearestNeighbor(std::vector<int> nearestNeighbor);
};

#endif
