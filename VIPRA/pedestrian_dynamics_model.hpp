#ifndef PEDESTRIANDYNAMICSMODEL_HPP
#define PEDESTRIANDYNAMICSMODEL_HPP

//#include <vector>
//#include <utility>
#include "data.hpp"

class PedestrianDynamicsModel
{
    public:
        virtual void setData(Data* initialData) = 0;
        virtual void precompute() = 0;
        virtual void update() = 0;
};

#endif