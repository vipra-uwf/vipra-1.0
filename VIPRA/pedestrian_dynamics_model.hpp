#ifndef PEDESTRIANDYNAMICSMODEL_HPP
#define PEDESTRIANDYNAMICSMODEL_HPP

//#include <vector>
//#include <utility>

class PedestrianDynamicsModel
{
    public:
        virtual .... setData(Data* initialData);
        virtual .... precompute() = 0;
        virtual .... update() = 0;
};

#endif