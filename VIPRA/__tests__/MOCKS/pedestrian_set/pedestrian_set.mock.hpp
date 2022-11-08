#ifndef PEDESTRIAN_SET_MOCK_HPP
#define PEDESTRIAN_SET_MOCK_HPP

#include "../../../Extendable/pedestrianset/pedestrian_set.hpp"

class PedestrianSetMock : public PedestrianSet {
 public:
  void configure(const CONFIG_MAP& configMap) override {}

  void initialize(ENTITY_SET pedestrianCount) override {}

  const DimVector& getPedestrianCoordinates() const noexcept override { return pedCoords; }

  int getNumPedestrians() const noexcept override { return pedCoords.size(); }

  void removePedestrian(size_t pedestrianIndex) override {}

  const DimVector&                    getVelocities() const noexcept override {}
  const std::vector<FLOATING_NUMBER>& getSpeeds() const noexcept override {}
  const std::vector<int>&             getIds() const noexcept override {}

  void setNumPedestrians(int numPedestrians) override {}

  void setPedestrianCoordinates(const Dimensions& coords, size_t index) override {}
  void setPedestrianCoordinates(Dimensions&& coords, size_t index) override {}
  void setPedestrianCoordinates(DimVector&& coordinates) noexcept override {}
  void setPedestrianCoordinates(const DimVector& coordinates) noexcept override {}

  void setVelocity(const Dimensions& velocity, size_t index) override {}
  void setVelocity(Dimensions&& velocity, size_t index) override {}
  void setVelocities(const DimVector& velocities) noexcept override {}
  void setVelocities(DimVector&& velocities) noexcept override {}

  void setSpeeds(const std::vector<FLOATING_NUMBER>& speedsMetersPerSecond) noexcept override {}
  void setSpeeds(std::vector<FLOATING_NUMBER>&& speedsMetersPerSecond) noexcept override {}
  void setSpeed(FLOATING_NUMBER speed, size_t index) override {}

  void setIds(std::vector<int> ids) override {}

 private:
  DimVector pedCoords = {
      {0.89, 3.1},       {1.68, 3.1},       {2.47, 3.1},       {3.25, 3.1},       {4.04, 3.1},
      {4.83, 3.1},       {5.62, 3.1},       {6.4, 3.1},        {7.19, 3.1},       {7.98, 3.1},
      {8.76, 3.1},       {9.55, 3.1},       {10.34, 3.1},      {11.13, 3.1},      {11.91, 3.1},
      {12.7, 3.1},       {13.9, 3.1},       {15.09, 3.1},      {15.88, 3.1},      {16.66, 3.1},
      {17.450001, 3.1},  {18.24, 3.1},      {0.89, 2.64},      {1.68, 2.64},      {2.47, 2.64},
      {3.25, 2.64},      {4.04, 2.64},      {4.83, 2.64},      {5.62, 2.64},      {6.4, 2.64},
      {7.19, 2.64},      {7.98, 2.64},      {8.76, 2.64},      {9.55, 2.64},      {10.34, 2.64},
      {11.13, 2.64},     {11.91, 2.64},     {12.7, 2.64},      {13.9, 2.64},      {15.09, 2.64},
      {15.88, 2.64},     {16.66, 2.64},     {17.450001, 2.64}, {18.24, 2.64},     {0.89, 2.19},
      {1.68, 2.19},      {2.47, 2.19},      {3.25, 2.19},      {4.04, 2.19},      {4.83, 2.19},
      {5.62, 2.19},      {6.4, 2.19},       {7.19, 2.19},      {7.98, 2.19},      {8.76, 2.19},
      {9.55, 2.19},      {10.34, 2.19},     {11.13, 2.19},     {11.91, 2.19},     {12.7, 2.19},
      {13.9, 2.19},      {15.09, 2.19},     {15.88, 2.19},     {16.66, 2.19},     {17.450001, 2.19},
      {18.24, 2.19},     {0.89, 0.36},      {1.68, 0.36},      {2.47, 0.36},      {3.25, 0.36},
      {4.04, 0.36},      {4.83, 0.36},      {5.62, 0.36},      {6.4, 0.36},       {7.19, 0.36},
      {7.98, 0.36},      {8.76, 0.36},      {9.55, 0.36},      {10.34, 0.36},     {11.13, 0.36},
      {11.91, 0.36},     {12.7, 0.36},      {13.9, 0.36},      {15.09, 0.36},     {15.88, 0.36},
      {16.66, 0.36},     {17.450001, 0.36}, {18.24, 0.36},     {0.89, 0.82},      {1.68, 0.82},
      {2.47, 0.82},      {3.25, 0.82},      {4.04, 0.82},      {4.83, 0.82},      {5.62, 0.82},
      {6.4, 0.82},       {7.19, 0.82},      {7.98, 0.82},      {8.76, 0.82},      {9.55, 0.82},
      {10.34, 0.82},     {11.13, 0.82},     {11.91, 0.82},     {12.7, 0.82},      {13.9, 0.82},
      {15.09, 0.82},     {15.88, 0.82},     {16.66, 0.82},     {17.450001, 0.82}, {18.24, 0.82},
      {0.89, 1.27},      {1.68, 1.27},      {2.47, 1.27},      {3.25, 1.27},      {4.04, 1.27},
      {4.83, 1.27},      {5.62, 1.27},      {6.4, 1.27},       {7.19, 1.27},      {7.98, 1.27},
      {8.76, 1.27},      {9.55, 1.27},      {10.34, 1.27},     {11.13, 1.27},     {11.91, 1.27},
      {12.7, 1.27},      {13.9, 1.27},      {15.09, 1.27},     {15.88, 1.27},     {16.66, 1.27},
      {17.450001, 1.27}, {18.24, 1.27},     {19.43, 3.05},     {20.58, 3.05},     {21.719999, 3.05},
      {19.43, 2.52},     {20.58, 2.52},     {21.719999, 2.52}, {19.43, 0.41},     {20.58, 0.41},
      {21.719999, 0.41}, {19.43, 0.94},     {20.58, 0.94},     {21.719999, 0.94}};
};

#endif