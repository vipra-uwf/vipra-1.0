#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include <vector>
#include "../../Base/definitions/type_definitions.hpp"
#include "../../Base/definitions/dimensions.hpp"

class PedestrianSet
{
    public:
        virtual ~PedestrianSet() = default;
        
        virtual void                                    configure(CONFIG_MAP* configMap)                        = 0;
        virtual void                                    initialize(size_t pedestrianCount)                      = 0;
        virtual void                                    removePedestrian(int pedestrianIndex)                   = 0;
        virtual int                                     getNumPedestrians()                     const noexcept  = 0;
        // TODO: this needs to be changed to returning a const reference -RG
        //          keeping it as a raw pointer :( because goals needs completely updated to support otherwise
        virtual       std::vector<Dimensions>*          getPedestrianCoordinates()              noexcept   = 0;
        virtual const std::vector<Dimensions>&          getGoalCoordinates()                    const noexcept  = 0;
        virtual const std::vector<Dimensions>&          getVelocities()                         const noexcept  = 0;
        virtual const std::vector<FLOATING_NUMBER>&     getSpeeds()                             const noexcept  = 0;
        virtual const std::vector<int>&                 getIds()                                const noexcept  = 0;

        virtual void setNumPedestrians(int numPedestrians)                                              = 0;
        virtual void setPedestrianCoordinates(std::vector<Dimensions> coordinates)                      = 0;
        virtual void setGoalCoordinates(std::vector<Dimensions> goalCoordinates)                        = 0;
        virtual void setVelocities(std::vector<Dimensions> velocities)                                  = 0;
        virtual void setSpeeds(std::vector<FLOATING_NUMBER> speedsMetersPerSecond)                      = 0;
        virtual void setIds(std::vector<int> ids)                                                       = 0;
};

#endif
