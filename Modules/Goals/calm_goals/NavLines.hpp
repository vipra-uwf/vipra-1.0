
#include "../../../VIPRA/Base/definitions/type_definitions.hpp"

struct NavLine {
  Dimensions            start;
  Dimensions            end;
  std::vector<NavLine&> greater;
  std::vector<NavLine&> lesser;
};

bool
isLineVertical(const NavLine& line) {
  return (line.start.axis[0] == line.end.axis[0]);
}

void
addLine(NavLine& rootLine, NavLine& newLine) {

  FLOATING_NUMBER startX = rootLine.start.axis[0];
  FLOATING_NUMBER endX = rootLine.end.axis[0];

  FLOATING_NUMBER oldVal;
  FLOATING_NUMBER newVal;

  if (startX == endX) {
    oldVal = rootLine.start.axis[0];
    newVal = newLine.end.axis[0];
    // vertical
  } else {
    // horizontal
    oldVal = rootLine.start.axis[1];
    newVal = newLine.end.axis[1];
  }

  if (newVal > oldVal) {
    rootLine.greater.push_back(newLine);
  } else {
    rootLine.lesser.push_back(newLine);
  }
}

FLOATING_NUMBER
getDistanceToLine(const NavLine& line, const Dimensions& coords) {

  // check if line is reachable

  if (isLineVertical(line)) {

  } else {
  }
}

const NavLine&
findNearestNavLine(const NavLine& rootLine, const Dimensions& coords) {

  FLOATING_NUMBER rootVal;
  FLOATING_NUMBER newVal;

  if (isLineVertical(rootLine)) {
    rootVal = rootLine.start.axis[0];
    newVal = coords.axis[0];
  } else {
    rootVal = rootLine.start.axis[1];
    newVal = coords.axis[1];
  }

  if (newVal > rootVal) {

  } else {
  }
}