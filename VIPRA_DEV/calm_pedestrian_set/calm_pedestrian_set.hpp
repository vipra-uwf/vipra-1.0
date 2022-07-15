#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <utility>
#include <string>
#include <numeric>


#include "../Base/definitions/movement_definitions.hpp"
#include "../Interfaces/pedestrianset/pedestrian_set.hpp"

class CalmPedestrianSet: public PedestrianSet
{
    private:
        int numPedestrians;

        std::vector<Dimensions> pedestrianCoordinates;
        std::vector<Dimensions> goalCoordinates;
        std::vector<Dimensions> velocities;

        std::vector<FLOATING_NUMBER> speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER> massesKg;
        std::vector<FLOATING_NUMBER> reactionTimes;
        std::vector<FLOATING_NUMBER> desiredSpeeds;
        std::vector<Dimensions> propulsionForces;
        std::vector<std::pair<std::string, int>> nearestNeighbors;
        std::vector<FLOATING_NUMBER> priorities;
        std::vector<MovementDefinitions> movementStates;
        std::vector<int> startingAisles;
        std::vector<FLOATING_NUMBER> shoulderLengths;
        std::vector<int> ids;

        FLOATING_NUMBER startMass;
        FLOATING_NUMBER startReaction_time;
        FLOATING_NUMBER startDesired_speed;

    public:
        CalmPedestrianSet();

        virtual void configure(CONFIG_MAP* configMap);
        virtual void initialize(size_t pedestrianCount);
        virtual void removePedestrian(int pedestrianIndex);

        virtual int getNumPedestrians();
        virtual std::vector<int>* getIds();
        virtual std::vector<Dimensions>* getPedestrianCoordinates();
        virtual std::vector<Dimensions>* getGoalCoordinates();
        virtual std::vector<Dimensions>* getVelocities();
        virtual std::vector<FLOATING_NUMBER>* getSpeeds();

        virtual void setNumPedestrians(int numPedestrians);
        virtual void setIds(
                std::vector<int> ids);
        virtual void setPedestrianCoordinates(
				std::vector<Dimensions> coordinates);
        virtual void setGoalCoordinates(
				std::vector<Dimensions> goalCoordinates);
        virtual void setVelocities(
				std::vector<Dimensions> velocities);
        virtual void setSpeeds(
				std::vector<FLOATING_NUMBER> speedsMetersPerSecond);

        // virtual ~CalmPedestrianSet();

        std::vector<FLOATING_NUMBER>* getMasses();
        std::vector<FLOATING_NUMBER>* getReactionTimes();
        std::vector<FLOATING_NUMBER>* getDesiredSpeeds();
        std::vector<Dimensions>* getPropulsionForces();
        std::vector<FLOATING_NUMBER>* getRepulsionForces();
        std::vector<std::pair<std::string, int>>* getNearestNeighbors();
        std::vector<FLOATING_NUMBER>* getPriorities();
        std::vector<MovementDefinitions>* getMovementStates();
        std::vector<int>* getStartingAisles();
        std::vector<FLOATING_NUMBER>* getShoulderLengths();

        void setMasses(std::vector<FLOATING_NUMBER> massesKg);
        void setReactionTimes(std::vector<FLOATING_NUMBER> reactionTimes);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER> desiredSpeeds);
        void setPropulsionForces(std::vector<Dimensions> propulsionForces);
        void setRepulsionForces(std::vector<FLOATING_NUMBER> repulsionForces);
        void setNearestNeighbors(
          std::vector<std::pair<std::string, int>> nearestNeighbors);
        void setPriorities(std::vector<FLOATING_NUMBER> priorities);
        void setMovementStates(std::vector<MovementDefinitions> movementStates);
        void setStartingAisles(std::vector<int> startingAisles);
        void setShoulderLengths(std::vector<FLOATING_NUMBER> shoulderLengths);

    private:
      static constexpr FLOATING_NUMBER START_GOAL_X           = 0.00f;
      static constexpr FLOATING_NUMBER START_GOAL_Y           = 0.00f;
      static constexpr FLOATING_NUMBER START_VELOCITY_X       = 0.00f;
      static constexpr FLOATING_NUMBER START_VELOCITY_Y       = 0.00f;
      static constexpr FLOATING_NUMBER START_PROP_FORCE       = 0.00f;
      static constexpr FLOATING_NUMBER START_NEAREST_NEIGHBOR = 0.00f;
      static constexpr FLOATING_NUMBER START_SPEED            = 0.00f;
      static constexpr FLOATING_NUMBER START_SHOULDER_WIDTH   = 0.10f;
};

#endif
