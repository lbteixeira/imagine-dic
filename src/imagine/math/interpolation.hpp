#pragma once

#include "coefficients.hpp"
#include <array>
#include <memory>
#include <vector>

namespace Imagine {
  namespace Math {
    class Interpolator {
      public:
        Interpolator(unsigned int, unsigned int);

        const std::array<int, 4> getPixelsCoordsAroundPoint(double, double) const;

      private:
        unsigned int _numPixelsX, _numPixelsY;
        std::unique_ptr<CoefficientsTable> _lookupTable;
    };

  }
}

