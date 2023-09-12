#ifndef VIPRA_BEHAVIORS_STIMULUS_HPP
#define VIPRA_BEHAVIORS_STIMULUS_HPP

#include <bitset>
#include <cstdint>
#include <unordered_map>

#include "definitions/dimensions.hpp"

#include "definitions/dsl_types.hpp"

#include "stimuli/source.hpp"
#include "util/caseless_str_comp.hpp"

namespace BHVR {
enum class StimulusType {
  AUDITORY,
  VISUAL,
};

struct Stimulus {
  std::bitset<2> type{};
  uid            id{};
};

struct StimulusSource {
  Stimulus stimulus;
  Source   location;
};

static inline auto get_stim_type(const std::string& type) -> StimulusType {
  static const std::unordered_map<std::string, StimulusType, CaselessStrCompare::Hash,
                                  CaselessStrCompare::Comp>
      TYPEMAP{{"auditory", StimulusType::AUDITORY}, {"visual", StimulusType::VISUAL}};
  return TYPEMAP.at(type);
}
}  // namespace BHVR

#endif