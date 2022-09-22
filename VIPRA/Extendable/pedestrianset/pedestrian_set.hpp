#ifndef PEDESTRIAN_SET_HPP
#define PEDESTRIAN_SET_HPP

#include "../../Base/definitions/type_definitions.hpp"

class PedestrianSet {
 public:
  virtual ~PedestrianSet() = default;

  virtual void configure(const CONFIG_MAP& configMap) = 0;
  virtual void initialize(size_t pedestrianCount) = 0;

  virtual void setCoordinates(DimVector&&) = 0;

  virtual const Dimensions& getPedestrianCoords(size_t index) const = 0;
  virtual const DimVector&  getAllPedCoords() const = 0;

  virtual size_t getNumPedestrians() const = 0;
};

#endif
