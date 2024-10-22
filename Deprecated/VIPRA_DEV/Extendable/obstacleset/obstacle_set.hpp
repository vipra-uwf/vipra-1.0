#ifndef OBSTACLE_SET_HPP
#define OBSTACLE_SET_HPP

#include <vector>
#include "../../Base/definitions/type_definitions.hpp"
#include "../../Base/definitions/dimensions.hpp"
class ObstacleSet
{
    public:
        static const std::vector<Dimensions> __empty__;

        virtual ~ObstacleSet() = default;
        
        virtual void                            configure(CONFIG_MAP* configMap)                                                    = 0;

        virtual void                            addObjects(const std::string& type, const std::vector<Dimensions>& locations)       = 0;
        virtual void                            setObstacleCoordinates(const std::vector<Dimensions>& coordinates)                  = 0;
        
        virtual int                             getNumObstacles()                           const noexcept                          = 0;
        virtual const std::vector<Dimensions>&  getObstacleCoordinates()                    const noexcept                          = 0;
        virtual const std::vector<Dimensions>&  getObjectsofType(const std::string& type)   const noexcept                          = 0;
        virtual const std::vector<std::string>& getObjectTypes()                            const noexcept                          = 0;
};

#endif
