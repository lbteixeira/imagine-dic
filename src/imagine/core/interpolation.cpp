#include "interpolation.hpp"
#include <memory>

namespace Imagine {
  namespace Core {
    Interpolator::Interpolator(std::size_t nX, std::size_t nY) :
      _numPixelsX(nX), _numPixelsY(nY),
      _lookupTable(std::make_unique<CoefficientsTable>(nX, nY)){
    }

  }
}
