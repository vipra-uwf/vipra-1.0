#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <numeric>
#include <string>
#include <utility>

#include "../../../VIPRA/Extendable/pedestrianset/pedestrian_set.hpp"

class CalmPedestrianSet : public PedestrianSet {
 public:
        CalmPedestrianSet();

        void configure(const CONFIG_MAP& configMap) override;
        void initialize(ENTITY_SET pedestrianCount) override;
        void removePedestrian(size_t pedestrianIndex) override;


        [[nodiscard]] int                                       getNumPedestrians()                                     const noexcept override;
        [[nodiscard]] const std::vector<int>&                   getIds()                                                const noexcept override;

        [[nodiscard]] const DimVector&            getPedestrianCoordinates()                              const noexcept override;
        [[nodiscard]] const DimVector&            getVelocities()                                         const noexcept override;
        [[nodiscard]] const DimVector&            getGoalCoordinates();
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

        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getMasses()                     const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getReactionTimes()              const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getDesiredSpeeds()              const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>&                     getShoulderLengths()            const noexcept;

        
        [[nodiscard]] const std::vector<int>&                                 getStartingAisles()             const noexcept;


        void setMasses(std::vector<FLOATING_NUMBER>& massesKg);
        void setReactionTimes(std::vector<FLOATING_NUMBER>& reactionTimes);
        void setDesiredSpeeds(std::vector<FLOATING_NUMBER>& desiredSpeeds);
        void setShoulderLengths(std::vector<FLOATING_NUMBER>& shoulderLengths);


 private:
    int numPedestrians;

    DimVector                   pedestrianCoordinates;
    DimVector                   goalCoordinates;
    DimVector                   velocities;



    std::vector<FLOATING_NUMBER>              speedsMetersPerSecond;
    std::vector<FLOATING_NUMBER>              massesKg;
    std::vector<FLOATING_NUMBER>              reactionTimes;
    std::vector<FLOATING_NUMBER>              desiredSpeeds;
    std::vector<FLOATING_NUMBER>              shoulderLengths;


    std::vector<int>                          ids;

    FLOATING_NUMBER startMass = 0.0f;
    FLOATING_NUMBER startReaction_time = 0.0f;
    FLOATING_NUMBER startDesired_speed = 0.0f;

    //Constants used for initializing data
    static constexpr FLOATING_NUMBER STARTING_VELOCITY_X = 0.0f;
    static constexpr FLOATING_NUMBER STARTING_VELOCITY_Y = 0.0f;
    
    static constexpr FLOATING_NUMBER STARTING_SPEED = 0.0f;

    static constexpr FLOATING_NUMBER STARTING_MASS = 0.0f;

    static constexpr FLOATING_NUMBER STARTING_REACTION_TIME = 0.0f;
    static constexpr FLOATING_NUMBER STARTING_DESIRED_SPEED = 0.0f;
    static constexpr FLOATING_NUMBER STARTING_PROP_FORCE = 0.0f;
    static constexpr FLOATING_NUMBER STARTING_NEAREST_NEIGHBOR = 0.0f;
    static constexpr FLOATING_NUMBER STARTING_SHOULDER_WIDTH = 0.0f;

};
#endif