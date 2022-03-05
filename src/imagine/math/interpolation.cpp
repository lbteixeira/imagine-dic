#include "interpolation.hpp"
#include <array>
#include <memory>

namespace Imagine {
  namespace Math {
    Interpolator::Interpolator(unsigned int nX, unsigned int nY) :
      _numPixelsX(nX), _numPixelsY(nY),
      _lookupTable(std::make_unique<CoefficientsTable>(nX, nY)){

    }

    const std::array<int, 4> Interpolator::getPixelsCoordsAroundPoint(double
        coordX, double coordY) const{

      std::array<int, 4> surroundingCoords;
      surroundingCoords = {int(coordX), int(coordX)+1,
                           int(coordY), int(coordY)+1};
      return surroundingCoords;
    }

  }
}
