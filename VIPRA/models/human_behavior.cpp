#include "human_behavior.hpp"

// Provide default definitions for methods to make extending much easier

HumanBehavior::HumanBehavior()
{

}

void HumanBehavior::initialize(PedestrianSet *pedestrianSet)
{

}

void HumanBehavior::update(FLOATING_NUMBER timestep)
{

}

bool HumanBehavior::select(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{
    return false;
}

bool HumanBehavior::decide(PedestrianSet *pedestrianSet, int pedestrianIndex)
{
    return false;
}

void HumanBehavior::act(PedestrianSet *pedestrianSet, int pedestrianIndex, FLOATING_NUMBER timestep)
{

}

void HumanBehavior::addStateDefinition(std::string const &stateDefinition)
{
    this->stateDefinitions.push_back(stateDefinition);
}

std::vector<std::string> HumanBehavior::getStateDefinitions() 
{
    return this->stateDefinitions;
}

void HumanBehavior::setRatioSelected(float ratioSelected)
{
    this->ratioSelected = ratioSelected;
}

float HumanBehavior::getRatioSelected()
{
    return this->ratioSelected;
}