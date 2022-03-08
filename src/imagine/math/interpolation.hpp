#pragma once

#include "coefficients.hpp"
#include <memory>
#include <vector>

namespace Imagine {
  namespace Math {
    class Interpolator {
      public:
        virtual double interpolateAtPoint(double x, double y) const = 0;

      protected:
        Interpolator(std::size_t nX, std::size_t nY);

      private:
        std::size_t _numPixelsX, _numPixelsY;
        std::unique_ptr<CoefficientsTable> _lookupTable;
    };
  }
}

