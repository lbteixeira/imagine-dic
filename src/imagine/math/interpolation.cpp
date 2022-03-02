#include "interpolation.hpp"
#include <array>

namespace Imagine {
  namespace Math {
    Interpolator::Interpolator(int nX, int nY) :
      numberPixelsX(nX), numberPixelsY(nY) {}

    const std::array<int, 4> Interpolator::getPixelsCoordsAroundPoint(double
        coordX, double coordY) const{

      std::array<int, 4> surroundingCoords;
      surroundingCoords = {int(coordX), int(coordX)+1,
                           int(coordY), int(coordY)+1};
      return surroundingCoords;
    }

    int Interpolator::positionInLookupForPoint(double coordX, double coordY){
      //TODO treat exception: coords out-of-bounds
      return int(coordY) * numberPixelsX + int(coordX);
    }



  }
}
