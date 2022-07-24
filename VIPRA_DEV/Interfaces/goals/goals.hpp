//should specify functionality for determining whether goals are met
//specification of the goal
    //time
    //state of the obstacles and pedestrians

#ifndef GOALS_HPP
#define GOALS_HPP 

#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

#include "../../Base/simulation/data/data.hpp"
#include "../../Base/definitions/type_definitions.hpp"
#include "../../Base/definitions/dimensions.hpp"

#include "../obstacleset/obstacle_set.hpp"

class Goals
{
    public:
        virtual ~Goals() = default;

        virtual void                        configure(CONFIG_MAP* configMap)                                                    = 0;
        virtual void                        initialize(const ObstacleSet&, const PedestrianSet&)                                = 0;

        virtual void                        updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&)                     = 0;

        virtual const Dimensions&           getCurrentGoal(size_t index)                                        const           = 0;
        virtual const Dimensions&           getEndGoal(size_t index)                                            const           = 0;

        virtual const DimsVector&           getAllCurrentGoals()                                                const noexcept  = 0;
        virtual const DimsVector&           getAllEndGoals()                                                    const noexcept  = 0;

        virtual void                        clearGoals()                                                        noexcept        = 0;

        virtual bool                        isPedestianGoalsMet(size_t)                                         const           = 0;
        virtual bool                        isSimulationGoalMet()                                               const noexcept  = 0;
};

#endif
