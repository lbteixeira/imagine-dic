#include "interpolation.hpp"
#include <array>

namespace Imagine {
  namespace Math {
    Interpolator::Interpolator(){}

    const std::array<int, 4> Interpolator::getPixelsCoordsAroundPoint(double
        coordX, double coordY) const{

      std::array<int, 4> surroundingCoords;
      surroundingCoords = {int(coordX), int(coordX)+1,
                           int(coordY), int(coordY)+1};
      return surroundingCoords;

    }
  }
}
