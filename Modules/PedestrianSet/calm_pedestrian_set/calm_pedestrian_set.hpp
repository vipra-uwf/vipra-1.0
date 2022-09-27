#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <numeric>
#include <string>
#include <utility>

#include "../../VIPRA_DEV/Base/definitions/race_status.hpp"
#include "../../VIPRA_DEV/Extendable/pedestrianset/pedestrian_set.hpp"
#include "../../definitions/type_definitions.hpp"

class CalmPedestrianSet : public PedestrianSet {
 public:
        void configure(const CONFIG_MAP& configMap) override;
        void initialize(size_t pedestrianCount) override;

        void setCoordinates(DimVector&&) override;

        const Dimensions& getPedestrianCoords(size_t index) const override;
        const DimVector&  getAllPedCoords() const override;


        [[nodiscard]] int                                       getNumPedestrians()                                     const noexcept override;
        [[nodiscard]] const std::vector<int>&                   getIds()                                                const noexcept override;

        [[nodiscard]] const DimVector&            getPedestrianCoordinates()                              const noexcept override;
        [[nodiscard]] const DimVector&            getVelocities()                                         const noexcept override;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&       getSpeeds()                                             const noexcept override;

        void                                    setNumPedestrians(int numPedestrians)                                           override;
        void                                    setIds(std::vector<int> ids)                                                    override;

        void                                    setPedestrianCoordinates(const Dimensions& coords, size_t index)                override;
        void                                    setPedestrianCoordinates(Dimensions&& coords, size_t index)                     override;
        void                                    setPedestrianCoordinates(const DimVector& coordinates)            noexcept override;
        void                                    setPedestrianCoordinates(DimVector&& coordinates)                 noexcept override;

        void                                    setVelocity(const Dimensions& velocity, size_t index)                           override;
        void                                    setVelocity(Dimensions&& velocity, size_t index)                                override;
        void                                    setVelocities(const DimVector& velocities)                        noexcept override;
        void                                    setVelocities(DimVector&& velocities)                             noexcept override;

        void                                    setSpeed(FLOATING_NUMBER speed, size_t index)                                   override; 
        void                                    setSpeeds(const std::vector<FLOATING_NUMBER>& speedsMetersPerSecond)            noexcept override;
        void                                    setSpeeds(std::vector<FLOATING_NUMBER>&& speedsMetersPerSecond)                 noexcept override;

        // virtual ~CalmPedestrianSet();

        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getMasses()                     const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getReactionTimes()              const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getDesiredSpeeds()              const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getRepulsionForces()            const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getPriorities()                 const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getShoulderLengths()            const noexcept;

        
        [[nodiscard]] const std::vector<int>&                                 getStartingAisles()             const noexcept;
        [[nodiscard]] const std::vector<int>&                                 getRaceCounter()                const noexcept;
        [[nodiscard]] const std::vector<int>&                                 getOpponentIDs()                const noexcept;
        
        [[nodiscard]] const DimVector&                                        getRacePositions()              const noexcept;
        [[nodiscard]] const DimVector&                                        getPropulsionForces()           const noexcept;

        [[nodiscard]] const std::vector<RaceStatus>&                          getRaceStatus()                 const noexcept;
        
        [[nodiscard]] const std::vector<bool>&                                getRaceFinished()               const noexcept;
        [[nodiscard]] const std::vector<bool>&                                getReleased()                   const noexcept;
        
        [[nodiscard]] const std::vector<std::pair<std::string, int>>&         getNearestNeighbors()           const noexcept;


        void setMasses(std::vector<FLOATING_NUMBER>&& massesKg);
        void setReactionTimes(std::vector<FLOATING_NUMBER>&& reactionTimes);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER>&& desiredSpeeds);
        void setPropulsionForces(DimVector&& propulsionForces);
        void setPropulsionForce(Dimensions&& propulsionForce, size_t index);
        void setRepulsionForces(std::vector<FLOATING_NUMBER>&& repulsionForces);
        void setNearestNeighbors(std::vector<std::pair<std::string, int>>&& nearestNeighbors);
        void setPriorities(std::vector<FLOATING_NUMBER>&& priorities);
        void setStartingAisles(std::vector<int>&& startingAisles);
        void setShoulderLengths(std::vector<FLOATING_NUMBER>&& shoulderLengths);
        void setRaceStatus(RaceStatus status, size_t pedestrianIndex);
        void setRaceCounter(int newCounter, size_t pedestrianIndex);
        void setOpponentID(int newID, size_t pedestrianIndex);
        void setRacePosition(Dimensions coordinates, size_t pedestrianIndex);
        void setRaceFinished(bool isFinished, size_t newID);
        void setReleased(bool hasReleased, size_t pedestrianIndex);

 private:
    int numPedestrians;

    DimVector                   pedestrianCoordinates;
    DimVector                   goalCoordinates;
    DimVector                   velocities;
    DimVector                   racePositions;
    DimVector                   propulsionForces;

    std::vector<std::pair<std::string, int>>  nearestNeighbors;



    std::vector<FLOATING_NUMBER>              speedsMetersPerSecond;
    std::vector<FLOATING_NUMBER>              massesKg;
    std::vector<FLOATING_NUMBER>              reactionTimes;
    std::vector<FLOATING_NUMBER>              desiredSpeeds;
    std::vector<FLOATING_NUMBER>              priorities;
    std::vector<FLOATING_NUMBER>              shoulderLengths;

    std::vector<RaceStatus>                   raceStatus;

    std::vector<int>                          ids;
    std::vector<int>                          raceCounter;
    std::vector<int>                          opponentIDs;
    std::vector<int>                          startingAisles;

    std::vector<bool>                         raceFinished;
    std::vector<bool>                         released;

    FLOATING_NUMBER startMass;
    FLOATING_NUMBER startReaction_time;
    FLOATING_NUMBER startDesired_speed;

    //Constants used for initializing data
    const FLOATING_NUMBER STARTING_VELOCITY_X = 0.0f;
    const FLOATING_NUMBER STARTING_VELOCITY_Y = 0.0f;
    
    const FLOATING_NUMBER STARTING_SPEED = 0.0f;

    const FLOATING_NUMBER STARTING_MASS = 0.0f;

    const FLOATING_NUMBER STARTING_REACTION_TIME = 0.0f;
    const FLOATING_NUMBER STARTING_DESIRED_SPEED = 0.0f;
    const FLOATING_NUMBER STARTING_PROP_FORCE = 0.0f;
    const FLOATING_NUMBER STARTING_NEAREST_NEIGHBOR = 0.0f;
    const FLOATING_NUMBER STARTING_SHOULDER_WIDTH = 0.0f;

};
#endif