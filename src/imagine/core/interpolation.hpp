#pragma once

#include "coefficients.hpp"
#include <memory>
#include <vector>

namespace Imagine {
  namespace Core {
    /**
     *  @brief Interface to the interpolation algorithms.
     */
    class Interpolator {
      public:
        /**
         * @brief Interpolates the pixel's intensity value at a given point.
         *
         * @param p Point where to interpolate.
         */
        virtual double
        interpolate(Utils::Point<double> p) const = 0;


      protected:
        Interpolator(std::size_t nX, std::size_t nY);
        virtual ~Interpolator();

      private:
        std::size_t _numPixelsX, _numPixelsY;
        std::unique_ptr<CoefficientsTable> _lookupTable;
    };
  }
}

