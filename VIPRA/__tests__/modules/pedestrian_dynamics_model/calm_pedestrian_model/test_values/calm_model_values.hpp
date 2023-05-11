#pragma once

#include <definitions/config_map.hpp>
#include <definitions/entitySet.hpp>

const VIPRA::EntitySet CALM_PEDESTRIAN_VIPRA_EntitySet = {
    {"pedestrians",
     {VIPRA::f3d{0.89, 3.1},       VIPRA::f3d{1.68, 3.1},       VIPRA::f3d{2.47, 3.1},       VIPRA::f3d{3.25, 3.1},
      VIPRA::f3d{4.04, 3.1},       VIPRA::f3d{4.83, 3.1},       VIPRA::f3d{5.62, 3.1},       VIPRA::f3d{6.4, 3.1},
      VIPRA::f3d{7.19, 3.1},       VIPRA::f3d{7.98, 3.1},       VIPRA::f3d{8.76, 3.1},       VIPRA::f3d{9.55, 3.1},
      VIPRA::f3d{10.34, 3.1},      VIPRA::f3d{11.13, 3.1},      VIPRA::f3d{11.91, 3.1},      VIPRA::f3d{12.7, 3.1},
      VIPRA::f3d{13.9, 3.1},       VIPRA::f3d{15.09, 3.1},      VIPRA::f3d{15.88, 3.1},      VIPRA::f3d{16.66, 3.1},
      VIPRA::f3d{17.450001, 3.1},  VIPRA::f3d{18.24, 3.1},      VIPRA::f3d{0.89, 2.64},      VIPRA::f3d{1.68, 2.64},
      VIPRA::f3d{2.47, 2.64},      VIPRA::f3d{3.25, 2.64},      VIPRA::f3d{4.04, 2.64},      VIPRA::f3d{4.83, 2.64},
      VIPRA::f3d{5.62, 2.64},      VIPRA::f3d{6.4, 2.64},       VIPRA::f3d{7.19, 2.64},      VIPRA::f3d{7.98, 2.64},
      VIPRA::f3d{8.76, 2.64},      VIPRA::f3d{9.55, 2.64},      VIPRA::f3d{10.34, 2.64},     VIPRA::f3d{11.13, 2.64},
      VIPRA::f3d{11.91, 2.64},     VIPRA::f3d{12.7, 2.64},      VIPRA::f3d{13.9, 2.64},      VIPRA::f3d{15.09, 2.64},
      VIPRA::f3d{15.88, 2.64},     VIPRA::f3d{16.66, 2.64},     VIPRA::f3d{17.450001, 2.64}, VIPRA::f3d{18.24, 2.64},
      VIPRA::f3d{0.89, 2.19},      VIPRA::f3d{1.68, 2.19},      VIPRA::f3d{2.47, 2.19},      VIPRA::f3d{3.25, 2.19},
      VIPRA::f3d{4.04, 2.19},      VIPRA::f3d{4.83, 2.19},      VIPRA::f3d{5.62, 2.19},      VIPRA::f3d{6.4, 2.19},
      VIPRA::f3d{7.19, 2.19},      VIPRA::f3d{7.98, 2.19},      VIPRA::f3d{8.76, 2.19},      VIPRA::f3d{9.55, 2.19},
      VIPRA::f3d{10.34, 2.19},     VIPRA::f3d{11.13, 2.19},     VIPRA::f3d{11.91, 2.19},     VIPRA::f3d{12.7, 2.19},
      VIPRA::f3d{13.9, 2.19},      VIPRA::f3d{15.09, 2.19},     VIPRA::f3d{15.88, 2.19},     VIPRA::f3d{16.66, 2.19},
      VIPRA::f3d{17.450001, 2.19}, VIPRA::f3d{18.24, 2.19},     VIPRA::f3d{0.89, 0.36},      VIPRA::f3d{1.68, 0.36},
      VIPRA::f3d{2.47, 0.36},      VIPRA::f3d{3.25, 0.36},      VIPRA::f3d{4.04, 0.36},      VIPRA::f3d{4.83, 0.36},
      VIPRA::f3d{5.62, 0.36},      VIPRA::f3d{6.4, 0.36},       VIPRA::f3d{7.19, 0.36},      VIPRA::f3d{7.98, 0.36},
      VIPRA::f3d{8.76, 0.36},      VIPRA::f3d{9.55, 0.36},      VIPRA::f3d{10.34, 0.36},     VIPRA::f3d{11.13, 0.36},
      VIPRA::f3d{11.91, 0.36},     VIPRA::f3d{12.7, 0.36},      VIPRA::f3d{13.9, 0.36},      VIPRA::f3d{15.09, 0.36},
      VIPRA::f3d{15.88, 0.36},     VIPRA::f3d{16.66, 0.36},     VIPRA::f3d{17.450001, 0.36}, VIPRA::f3d{18.24, 0.36},
      VIPRA::f3d{0.89, 0.82},      VIPRA::f3d{1.68, 0.82},      VIPRA::f3d{2.47, 0.82},      VIPRA::f3d{3.25, 0.82},
      VIPRA::f3d{4.04, 0.82},      VIPRA::f3d{4.83, 0.82},      VIPRA::f3d{5.62, 0.82},      VIPRA::f3d{6.4, 0.82},
      VIPRA::f3d{7.19, 0.82},      VIPRA::f3d{7.98, 0.82},      VIPRA::f3d{8.76, 0.82},      VIPRA::f3d{9.55, 0.82},
      VIPRA::f3d{10.34, 0.82},     VIPRA::f3d{11.13, 0.82},     VIPRA::f3d{11.91, 0.82},     VIPRA::f3d{12.7, 0.82},
      VIPRA::f3d{13.9, 0.82},      VIPRA::f3d{15.09, 0.82},     VIPRA::f3d{15.88, 0.82},     VIPRA::f3d{16.66, 0.82},
      VIPRA::f3d{17.450001, 0.82}, VIPRA::f3d{18.24, 0.82},     VIPRA::f3d{0.89, 1.27},      VIPRA::f3d{1.68, 1.27},
      VIPRA::f3d{2.47, 1.27},      VIPRA::f3d{3.25, 1.27},      VIPRA::f3d{4.04, 1.27},      VIPRA::f3d{4.83, 1.27},
      VIPRA::f3d{5.62, 1.27},      VIPRA::f3d{6.4, 1.27},       VIPRA::f3d{7.19, 1.27},      VIPRA::f3d{7.98, 1.27},
      VIPRA::f3d{8.76, 1.27},      VIPRA::f3d{9.55, 1.27},      VIPRA::f3d{10.34, 1.27},     VIPRA::f3d{11.13, 1.27},
      VIPRA::f3d{11.91, 1.27},     VIPRA::f3d{12.7, 1.27},      VIPRA::f3d{13.9, 1.27},      VIPRA::f3d{15.09, 1.27},
      VIPRA::f3d{15.88, 1.27},     VIPRA::f3d{16.66, 1.27},     VIPRA::f3d{17.450001, 1.27}, VIPRA::f3d{18.24, 1.27},
      VIPRA::f3d{19.43, 3.05},     VIPRA::f3d{20.58, 3.05},     VIPRA::f3d{21.719999, 3.05}, VIPRA::f3d{19.43, 2.52},
      VIPRA::f3d{20.58, 2.52},     VIPRA::f3d{21.719999, 2.52}, VIPRA::f3d{19.43, 0.41},     VIPRA::f3d{20.58, 0.41},
      VIPRA::f3d{21.719999, 0.41}, VIPRA::f3d{19.43, 0.94},     VIPRA::f3d{20.58, 0.94},     VIPRA::f3d{21.719999, 0.94}}}};

const VIPRA::Config::Map CALM_PEDESTRIAN_VIPRA_ConfigMap;
// =    std::string("\"mass\": \"1.000000\",\"reaction_time\": \"0.400000\",\"desired_speed\": \"1.000000\"");
