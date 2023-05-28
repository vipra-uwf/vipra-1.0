

#include <util/bool_latch.hpp>


namespace BHVR {
void Latch::latch() {
  set = true;
}

void Latch::unlatch() {
  set = false;
}

Latch::operator bool() const {
  return set;
}
}  // namespace BHVR