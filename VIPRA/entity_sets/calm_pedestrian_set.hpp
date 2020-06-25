#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include "pedestrian_set.hpp"

class CalmPedestrianSet: public PedestrianSet
{
    private:
        int numPedestrians;
        std::vector<FLOATING_NUMBER> coordinatesX;
        std::vector<FLOATING_NUMBER> coordinatesY;
        std::vector<FLOATING_NUMBER> goalCoordinatesX;
        std::vector<FLOATING_NUMBER> goalCoordinatesY;
        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;
        std::vector<FLOATING_NUMBER> reactionTimes;
        std::vector<FLOATING_NUMBER> desiredSpeeds;
        //TODO .. add getters and setters for velocity
        std::vector<FLOATING_NUMBER> currentVelocityX;
        std::vector<FLOATING_NUMBER> currentVelocityY;
        std::vector<FLOATING_NUMBER> propulsionForces;
        std::vector<FLOATING_NUMBER> repulsionForces;
        std::vector<int> nearestNeighbor;
        
        // should these exist?? should we read these in from file and
        // instead use our virtual setters? -- Alex
        void initializeSpeeds();
        void initializeGoalsX();
        void initializeGoalsY(); 
        // void initializeVelocityX();
        // void initializeVelocityY();
        void initializePropulsionForces();
        void initializeRepulsionForces();
        void initializeNearestNeighbors();

    public:
        CalmPedestrianSet();

        virtual void initializeValues();

        int getNumPedestrians();
        virtual std::vector<FLOATING_NUMBER>* getCoordinatesX();
        virtual std::vector<FLOATING_NUMBER>* getCoordinatesY();
        virtual std::vector<FLOATING_NUMBER>* getGoalCoordinatesX();
        virtual std::vector<FLOATING_NUMBER>* getGoalCoordinatesY();
        virtual std::vector<FLOATING_NUMBER>* getSpeeds();
        virtual std::vector<FLOATING_NUMBER>* getVelocityX();
        virtual std::vector<FLOATING_NUMBER>* getVelocityY();
        // TODO below getters probably shouldnt be virtual..
        // currently necessary for reader -- Alex
        virtual std::vector<FLOATING_NUMBER>* getMasses();
        virtual std::vector<FLOATING_NUMBER>* getReactionTimes();
        virtual std::vector<FLOATING_NUMBER>* getDesiredSpeeds();
        virtual std::vector<FLOATING_NUMBER>* getPropulsionForces();
        virtual std::vector<FLOATING_NUMBER>* getRepulsionForces();
        virtual std::vector<int>* getNearestNeighbor();
        
        void setNumPedestrians(int);
        virtual void setCoordinatesX(std::vector<FLOATING_NUMBER>);
        virtual void setCoordinatesY(std::vector<FLOATING_NUMBER>);
        virtual void setGoalCoordinatesX(std::vector<FLOATING_NUMBER>);
        virtual void setGoalCoordinatesY(std::vector<FLOATING_NUMBER>);
        virtual void setSpeeds(std::vector<FLOATING_NUMBER>);
        virtual void setVelocityX(std::vector<FLOATING_NUMBER>);
        virtual void setVelocityY(std::vector<FLOATING_NUMBER>);
        //TODO same as above getters.. below setters probably shouldn't be virtual -- Alex
        virtual void setMasses(std::vector<FLOATING_NUMBER>);
        virtual void setReactionTimes(std::vector<FLOATING_NUMBER>);
        virtual void setDesiredSpeeds(std::vector<FLOATING_NUMBER>);
        virtual void setPropulsionForces(std::vector<FLOATING_NUMBER>);
        virtual void setRepulsionForces(std::vector<FLOATING_NUMBER>);
        virtual void setNearestNeighbor(std::vector<int>);
};

#endif