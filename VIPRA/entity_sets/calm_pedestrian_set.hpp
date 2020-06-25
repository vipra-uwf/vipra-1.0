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
        std::vector<FLOATING_NUMBER> currentVelocityX;
        std::vector<FLOATING_NUMBER> currentVelocityY;
        
        void initializeSpeeds();
        void initializeGoalsX();
        void initializeGoalsY(); 

    public:
        
        int getNumPedestrians();

        std::vector<FLOATING_NUMBER>* getCoordinatesX();
        std::vector<FLOATING_NUMBER>* getCoordinatesY();
        std::vector<FLOATING_NUMBER>* getGoalCoordinatesX();
        std::vector<FLOATING_NUMBER>* getGoalCoordinatesY();
        std::vector<FLOATING_NUMBER>* getSpeeds();
        std::vector<FLOATING_NUMBER>* getMasses();
        std::vector<FLOATING_NUMBER>* getReactionTimes();
        std::vector<FLOATING_NUMBER>* getDesiredSpeeds();
        std::vector<FLOATING_NUMBER>* getVelocityX();
        std::vector<FLOATING_NUMBER>* getVelocityY();
        
        void setNumPedestrians(int);

        void setCoordinatesX(std::vector<FLOATING_NUMBER>);
        void setCoordinatesY(std::vector<FLOATING_NUMBER>);
        void setGoalCoordinatesX(std::vector<FLOATING_NUMBER>);
        void setGoalCoordinatesY(std::vector<FLOATING_NUMBER>);
        void setSpeeds(std::vector<FLOATING_NUMBER>);
        void setMasses(std::vector<FLOATING_NUMBER>);
        void setReactionTimes(std::vector<FLOATING_NUMBER>);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER>);
        void setVelocityX(std::vector<FLOATING_NUMBER>);
        void setVelocityY(std::vector<FLOATING_NUMBER>);
};

#endif