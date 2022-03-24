#pragma once

#include "coefficients.hpp"
//#include "image.hpp"
#include <memory>
#include <tuple>
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
       * @param neighborPx Vector of neighboring pixels, including x & y
       *                   coordinates and the intensity value.
       */
      virtual double
      interpolate(Point<double> p,
                  std::vector<std::tuple<int, int, int>> neighborPx) const = 0;

    protected:
      Interpolator(std::size_t nX, std::size_t nY);

    private:
      std::unique_ptr<CoefficientsTable> _lookupTable;
  };

  class BilinearInterpolator : public Interpolator {
    public:
      BilinearInterpolator(std::size_t nX, std::size_t nY);
      virtual ~BilinearInterpolator();

      virtual double
      interpolate(Point<double> p,
                  std::vector<std::tuple<int, int, int>> neighborPx) const override;
  };
}

