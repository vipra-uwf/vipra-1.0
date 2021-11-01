#include "id_ratio_selector.hpp"

IdRatioSelector::IdRatioSelector(FLOATING_NUMBER ratio)
{
    this->ratio = ratio;
}

bool IdRatioSelector::select(PedestrianSet *pedestrianSet, int pedestrianIndex)
{
    int pedestrianId = pedestrianSet->getIds()->at(pedestrianIndex);
    
    static const int divisor = static_cast<int>(1.0 / this->ratio);

    bool condition = pedestrianId % divisor == 0;

    return condition;
}
