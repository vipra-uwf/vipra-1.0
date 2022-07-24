#include "calm_goals.hpp"
#include <climits>
#include <algorithm>

size_t getClosestExit(const Dimensions&, const DimsVector&);
size_t dist(const Dimensions& first, const Dimensions& second);
bool inRange(FLOATING_NUMBER low, FLOATING_NUMBER high, FLOATING_NUMBER value);

CalmGoals::CalmGoals(){}

void CalmGoals::configure(CONFIG_MAP* configMap) {
    // TODO add some way for the user to input end goals for pedestrians -RG
}

void CalmGoals::initialize(const ObstacleSet& obstacleSet, const PedestrianSet& pedSet) {
    this->goalsMet = std::vector<bool>(pedSet.getNumPedestrians(), false);
    setupEndGoals(obstacleSet, pedSet);
}

void CalmGoals::setupEndGoals(const ObstacleSet& obstacleSet, const PedestrianSet& pedSet) {
    const DimsVector& pedestrians = pedSet.getPedestrianCoordinates();
    const DimsVector& exits = obstacleSet.getObjectsofType("exits");

    for(size_t i = 0; i < pedestrians.size(); ++i){
        this->endGoals.push_back(exits.at(getClosestExit(pedestrians[i], exits)));
        this->currGoals.push_back({0,0});
    }
}

size_t getClosestExit(const Dimensions& pedCoords, const DimsVector& exits) {
    size_t closestIndex = -1;
    int closest = INT_MAX;

    for(size_t i = 0; i < exits.size(); ++i){
        size_t curr = dist(pedCoords, exits.at(i));
        if(closest > curr){
            closest = curr;
            closestIndex = i;
        }
    }

    return closestIndex;
}

// TODO: assumes 2d -RG
size_t dist(const Dimensions& first, const Dimensions& second){
    int x = first[0] - second[0];
    int y = first[1] - second[1];
    return ((x*x) + (y*y));
}

// TODO: this assumes one exit in an airplane -RG
void CalmGoals::updatePedestrianGoals(const ObstacleSet& obstacleSet, const PedestrianSet& pedSet) {
    
    const DimsVector& pedCoords = pedSet.getPedestrianCoordinates();

    for(size_t i = 0; i < pedSet.getNumPedestrians(); ++i){
        bool inSeat = (pedCoords[i][0] <= endGoals[i][0] - 0.05 && !(pedCoords[i][1] > -0.3 && pedCoords[i][1] < 0.3));
        if(inSeat){
            currGoals[i] = Dimensions{pedCoords[i][0], 0};
        }else{
            if(pedCoords[i][0] >= endGoals[i][0] - 0.05){
                currGoals[i] = endGoals[i];
            }else{
                currGoals[i] = Dimensions{endGoals[i][0], 0};
            }
        }
        if(inRange(endGoals[i][0]-0.2, endGoals[i][0]+0.2, pedCoords[i][0]) && inRange(endGoals[i][1]-0.2, endGoals[i][1]+0.2, pedCoords[i][1])){
            setGoalsMet(i);
        }
    }
}

bool inRange(FLOATING_NUMBER low, FLOATING_NUMBER high, FLOATING_NUMBER value){
    return (low <= value && value <= high);
}

inline void CalmGoals::setGoalsMet(size_t index) {
    goalsMet[index] = true;
}

bool CalmGoals::isPedestianGoalsMet(size_t pedestrianIndex) const {
    return goalsMet.at(pedestrianIndex);
}

bool CalmGoals::isSimulationGoalMet() const noexcept {
    return std::all_of(this->goalsMet.begin(), this->goalsMet.end(), [](bool met){return met;});
}

const Dimensions& CalmGoals::getCurrentGoal(size_t index) const {
    return this->currGoals.at(index);
}

const Dimensions& CalmGoals::getEndGoal(size_t index) const {
    return this->endGoals.at(index);
}

const DimsVector& CalmGoals::getAllCurrentGoals() const noexcept {
    return this->currGoals;
}

const DimsVector& CalmGoals::getAllEndGoals() const noexcept {
    return this->endGoals;
}

void CalmGoals::clearGoals()  noexcept {
    this->currGoals.clear();
    this->endGoals.clear();
}