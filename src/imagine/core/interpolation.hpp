#pragma once

#include "coefficients.hpp"
//#include "image.hpp"
#include <memory>
#include <vector>

namespace Imagine {
  /**
   *  @brief Interface to the interpolation algorithms.
   */
  class Interpolator {
    public:
      virtual ~Interpolator();
      /**
       * @brief Interpolates the pixel's intensity value at a given point.
       *
       * @param p Point where to interpolate.
       */
      virtual double
      interpolate(Point<double> p) const = 0;

    protected:
      Interpolator();

    private:
      std::unique_ptr<CoefficientsTable> _lookupTable;
  };

  class BilinearInterpolator : public Interpolator {
    public:
      BilinearInterpolator();
      virtual ~BilinearInterpolator();

      virtual double
      interpolate(Point<double> p) const override;
  };
}

