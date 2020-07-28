#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include "../simulation/data.hpp"
#include "../goals/goal.hpp"

class InputDataLoader
{
    public:
        virtual void storeData(Data* data) = 0;
};

#endif
