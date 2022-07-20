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

        std::vector<Dimensions>                   pedestrianCoordinates;
        std::vector<Dimensions>                   goalCoordinates;
        std::vector<Dimensions>                   velocities;

        std::vector<FLOATING_NUMBER>              speedsMetersPerSecond;
        std::vector<FLOATING_NUMBER>              massesKg;
        std::vector<FLOATING_NUMBER>              reactionTimes;
        std::vector<FLOATING_NUMBER>              desiredSpeeds;
        std::vector<Dimensions>                   propulsionForces;
        std::vector<std::pair<std::string, int>>  nearestNeighbors;
        std::vector<FLOATING_NUMBER>              priorities;
        std::vector<MovementDefinitions>          movementStates;
        std::vector<int>                          startingAisles;
        std::vector<FLOATING_NUMBER>              shoulderLengths;
        std::vector<int>                          ids;

        FLOATING_NUMBER startMass;
        FLOATING_NUMBER startReaction_time;
        FLOATING_NUMBER startDesired_speed;

    public:
        CalmPedestrianSet();

        void                                    configure(CONFIG_MAP* configMap)                                      override;
        void                                    initialize(size_t pedestrianCount)                                    override;
        void                                    removePedestrian(int pedestrianIndex)                                 override;

        int                                     getNumPedestrians()                                    const noexcept override;
        const std::vector<int>&                 getIds()                                               const noexcept override;
        // TODO: needs updated, more in interface -RG
        [[nodiscard]] std::vector<Dimensions>*                  getPedestrianCoordinates()                             noexcept override;
        [[nodiscard]] const std::vector<Dimensions>&            getGoalCoordinates()                                   const noexcept override;
        [[nodiscard]] const std::vector<Dimensions>&            getVelocities()                                        const noexcept override;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&       getSpeeds()                                            const noexcept override;

        void                                    setNumPedestrians(int numPedestrians)                                 override;
        void                                    setIds(std::vector<int> ids)                                          override;
        void                                    setPedestrianCoordinates(Dimensions coords, size_t index)             override;
        void                                    setPedestrianCoordinates(std::vector<Dimensions> coordinates)         override;
        void                                    setGoalCoordinates(std::vector<Dimensions> goalCoordinates)           override;
        void                                    setVelocities(std::vector<Dimensions> velocities)                     override;
        void                                    setVelocity(Dimensions velocity, size_t index)                        override;
        void                                    setSpeeds(std::vector<FLOATING_NUMBER> speedsMetersPerSecond)         override;
        void                                    setSpeed(FLOATING_NUMBER speed, size_t index)                         override;

        // virtual ~CalmPedestrianSet();

        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getMasses()                     const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getReactionTimes()              const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getDesiredSpeeds()              const noexcept;
        [[nodiscard]] const std::vector<Dimensions>&                          getPropulsionForces()           const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getRepulsionForces()            const noexcept;
        [[nodiscard]] const std::vector<std::pair<std::string, int>>&         getNearestNeighbors()           const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getPriorities()                 const noexcept;
        [[nodiscard]] const std::vector<MovementDefinitions>&                 getMovementStates()             const noexcept;
        [[nodiscard]] const std::vector<int>&                                 getStartingAisles()             const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getShoulderLengths()            const noexcept;


        // TODO add move semantics -RG

        void setMasses(std::vector<FLOATING_NUMBER> massesKg);
        void setReactionTimes(std::vector<FLOATING_NUMBER> reactionTimes);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER> desiredSpeeds);
        void setPropulsionForces(std::vector<Dimensions> propulsionForces);
        void setPropulsionForce(Dimensions propulsionForce, size_t index);
        void setRepulsionForces(std::vector<FLOATING_NUMBER> repulsionForces);
        void setNearestNeighbors(std::vector<std::pair<std::string, int>> nearestNeighbors);
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
