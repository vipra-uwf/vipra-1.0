#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <vector>
#include "../type_definitions.hpp"

class PedestrianSet
{
    public:
       
        virtual int getNumPedestrians() = 0;

        virtual std::vector<FLOATING_NUMBER>* getCoordinatesX() = 0;
        virtual std::vector<FLOATING_NUMBER>* getCoordinatesY() = 0;
        virtual std::vector<FLOATING_NUMBER>* getGoalCoordinatesX() = 0;
        virtual std::vector<FLOATING_NUMBER>* getGoalCoordinatesY() = 0;
        virtual std::vector<FLOATING_NUMBER>* getSpeeds() = 0;
        virtual std::vector<FLOATING_NUMBER>* getVelocityX() = 0;
        virtual std::vector<FLOATING_NUMBER>* getVelocityY() = 0;
        
        void setNumPedestrians(int);

        virtual void setCoordinatesX(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setCoordinatesY(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setGoalCoordinatesX(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setGoalCoordinatesY(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setSpeeds(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setVelocityX(std::vector<FLOATING_NUMBER>) = 0;
        virtual void setVelocityY(std::vector<FLOATING_NUMBER>) = 0;
};

#endif
