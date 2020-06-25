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
        
        // should these exist?? should we read these in from file and
        // instead use our virtual setters? -- Alex
        void initializeSpeeds();
        void initializeGoalsX();
        void initializeGoalsY(); 

    public:

        CalmPedestrianSet();

        int getNumPedestrians();

        virtual std::vector<FLOATING_NUMBER>* getCoordinatesX();
        virtual std::vector<FLOATING_NUMBER>* getCoordinatesY();
        virtual std::vector<FLOATING_NUMBER>* getGoalCoordinatesX();
        virtual std::vector<FLOATING_NUMBER>* getGoalCoordinatesY();
        virtual std::vector<FLOATING_NUMBER>* getSpeeds();
        virtual std::vector<FLOATING_NUMBER>* getVelocityX();
        virtual std::vector<FLOATING_NUMBER>* getVelocityY();
        std::vector<FLOATING_NUMBER>* getMasses();
        std::vector<FLOATING_NUMBER>* getReactionTimes();
        std::vector<FLOATING_NUMBER>* getDesiredSpeeds();
        
        void setNumPedestrians(int);

        virtual void setCoordinatesX(std::vector<FLOATING_NUMBER>);
        virtual void setCoordinatesY(std::vector<FLOATING_NUMBER>);
        virtual void setGoalCoordinatesX(std::vector<FLOATING_NUMBER>);
        virtual void setGoalCoordinatesY(std::vector<FLOATING_NUMBER>);
        virtual void setSpeeds(std::vector<FLOATING_NUMBER>);
        virtual void setVelocityX(std::vector<FLOATING_NUMBER>);
        virtual void setVelocityY(std::vector<FLOATING_NUMBER>);
        void setMasses(std::vector<FLOATING_NUMBER>);
        void setReactionTimes(std::vector<FLOATING_NUMBER>);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER>);
};

#endif