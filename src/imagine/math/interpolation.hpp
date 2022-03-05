#pragma once

#include "coefficients.hpp"
#include <memory>
#include <vector>

namespace Imagine {
  namespace Math {
    class Interpolator {
      public:
        Interpolator(unsigned int, unsigned int);
        double interpolateAtPoint(double, double) const;

      private:
        unsigned int _numPixelsX, _numPixelsY;
        std::unique_ptr<CoefficientsTable> _lookupTable;
    };

  }
}

