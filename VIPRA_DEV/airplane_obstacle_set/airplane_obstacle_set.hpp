#ifndef AIRPLANE_OBSTACLE_SET
#define AIRPLANE_OBSTACLE_SET

#include "../Interfaces/obstacleset/obstacle_set.hpp"

class AirplaneObstacleSet: public ObstacleSet 
{
   private:
        ENTITY_SET objects;
        std::vector<std::string> types;

        std::vector<FLOATING_NUMBER> aisles; //should i make these two one vector of pairs? or a vector of dimensions? -EL
        std::vector<FLOATING_NUMBER> aislesSize;
    public:
                                                        AirplaneObstacleSet();
       
        void                                            configure(CONFIG_MAP* configMap)                                   override;
        
        void                                            setObstacleCoordinates(const std::vector<Dimensions>& coordinates) override;

        void                                            setAisles(const std::vector<FLOATING_NUMBER>&);
        void                                            setAislesSize(const std::vector<FLOATING_NUMBER>&);

        void                                            addObjects(const std::string& type, const std::vector<Dimensions>& locations) override;
        
        int                                               getNumAisles()                            const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>& getAisles()                               const noexcept;
        [[nodiscard]] const std::vector<FLOATING_NUMBER>& getAislesSize()                           const noexcept;

        int                                             getNumObstacles()                           const noexcept  override;
        [[nodiscard]] const std::vector<Dimensions>&    getObstacleCoordinates()                    const noexcept  override;

        [[nodiscard]] const std::vector<Dimensions>&    getObjectsofType(const std::string& type)   const noexcept  override;
        [[nodiscard]] const std::vector<std::string>&   getObjectTypes()                            const noexcept  override;
};

#endif