#ifndef CALM_GOALS
#define CALM_GOALS

#include "../Interfaces/goals/goals.hpp"


class CalmGoals: public Goals
{

    private:
        DimsVector          currGoals;
        DimsVector          endGoals;
        std::vector<bool>   goalsMet;

        void                                        setupEndGoals(const ObstacleSet&, const PedestrianSet&)                             ;
        inline void                                 setGoalsMet(size_t index)                                                           ;

    public: 

        CalmGoals();

        void                                        configure(CONFIG_MAP* configMap)                                                    override;
        void                                        initialize(const ObstacleSet&, const PedestrianSet&)                                override;

        void                                        updatePedestrianGoals(const ObstacleSet&, const PedestrianSet&)                     override;

        [[nodiscard]] const Dimensions&             getCurrentGoal(size_t index)                                    const               override;
        [[nodiscard]] const Dimensions&             getEndGoal(size_t index)                                        const               override;

        [[nodiscard]] const DimsVector&             getAllCurrentGoals()                                            const noexcept      override;
        [[nodiscard]] const DimsVector&             getAllEndGoals()                                                const noexcept      override;

        void                                        clearGoals()                                                    noexcept            override;

        bool                                        isPedestianGoalsMet(size_t)                                     const               override;
        bool                                        isSimulationGoalMet()                                           const noexcept      override;

};

#endif