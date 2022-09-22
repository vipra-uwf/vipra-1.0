#ifndef CALM_PEDESTRIAN_SET
#define CALM_PEDESTRIAN_SET

#include <numeric>
#include <string>
#include <utility>

#include "../../VIPRA_DEV/Base/definitions/movement_definitions.hpp"
#include "../../VIPRA_DEV/Base/definitions/race_status.hpp"
#include "../../VIPRA_DEV/Extendable/pedestrianset/pedestrian_set.hpp"

class CalmPedestrianSet : public PedestrianSet {
 public:
  void configure(const CONFIG_MAP& configMap) override;
  void initialize(size_t pedestrianCount) override;

  void setCoordinates(DimVector&&) override;

  const Dimensions& getPedestrianCoords(size_t index) const override;
  const DimVector&  getAllPedCoords() const override;

  size_t getNumPedestrians() const override;

 private:
};
#endif