#ifndef CALMPEDESTRIANMODEL_HPP
#define CALMPEDESTRIANMODEL_HPP

//#include <vector>
//#include <utility>

class CalmPedestrianModel : PedestrianDynamicsModel
{
    public:
        virtual .... setData(Data* initialData);
        virtual .... precompute() = 0;
        virtual .... update() = 0;
};

#endif