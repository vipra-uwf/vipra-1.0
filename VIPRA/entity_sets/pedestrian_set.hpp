#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <vector>
#include "../type_definitions.hpp"

class PedestrianSet
{
    public:
        //TODO .. may not be necessary but is for now because of reader structure
        virtual void initializeValues() = 0;

        virtual int getNumPedestrians() = 0;
        virtual int getNumDimensions() = 0;
        virtual std::vector<std::vector<FLOATING_NUMBER>>* getPedestrianCoordinates() = 0;
        virtual std::vector<std::vector<FLOATING_NUMBER>>* getGoalCoordinates() = 0;
        virtual std::vector<FLOATING_NUMBER>* getSpeeds() = 0;
        virtual std::vector<std::vector<FLOATING_NUMBER>>* getVelocitys() = 0;

        // TODO.. necessary gettersto align with our storeData. I dont like it though -- Alex
        virtual std::vector<FLOATING_NUMBER>* getMasses() = 0;
        virtual std::vector<FLOATING_NUMBER>* getReactionTimes() = 0;
        virtual std::vector<FLOATING_NUMBER>* getDesiredSpeeds() = 0;
        virtual std::vector<FLOATING_NUMBER>* getPropulsionForces() = 0;
        virtual std::vector<FLOATING_NUMBER>* getRepulsionForces() = 0;
        virtual std::vector<int>* getNearestNeighbor() = 0;

        virtual void setNumPedestrians(int) = 0;
        virtual void setNumDimensions(int) = 0;
        virtual void setPedestrianCoordinates(std::vector<std::vector<FLOATING_NUMBER>>) = 0;
        virtual void setGoalCoordinates(std::vector<std::vector<FLOATING_NUMBER>>) = 0;
        virtual void setSpeeds(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setVelocitys(std::vector<std::vector<FLOATING_NUMBER>>) = 0;
        
        //TODO same as necessary getters.. these are unique to Calm and should'nt be virtual --Alex
        virtual void setMasses(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setReactionTimes(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setDesiredSpeeds(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setPropulsionForces(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setRepulsionForces(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setNearestNeighbor(std::vector<int>) = 0;
};

#endif
