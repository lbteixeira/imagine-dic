#include "interpolation.hpp"
#include <array>
#include <memory>

namespace Imagine {
  namespace Math {
    Interpolator::Interpolator(unsigned int nX, unsigned int nY) :
      _numPixelsX(nX), _numPixelsY(nY),
      _lookupTable(std::make_unique<CoefficientsTable>(nX, nY)){
    }

  }
}
