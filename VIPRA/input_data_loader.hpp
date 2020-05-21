#ifndef INPUT_DATALOADER_HPP
#define INPUT_DATALOADER_HPP

#include <vector>
#include <utility>

#include "data.hpp"

class InputDataLoader
{
    public:
        virtual void writeData(Data* data) = 0;
};

#endif
