#pragma once

#include "coefficients.hpp"
#include <memory>
#include <vector>

typedef std::vector<std::array<int, 3>> vector_px;

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
      double
      interpolate(const Point<double>& p, const vector_px& neighborPx) const;

    protected:
      Interpolator(std::size_t nX, std::size_t nY);

      virtual const std::vector<double>
      _calculateCoefficients(const Point<double>& p,
          const vector_px& neighborPx) const = 0;

    private:
      CoefficientsTable _lookupTable;
  };

  class BilinearInterpolator : public Interpolator {
    public:
      BilinearInterpolator(std::size_t nX, std::size_t nY);
      virtual ~BilinearInterpolator();

    protected:
      virtual const std::vector<double>
      _calculateCoefficients(const Point<double>& p,
          const vector_px& neighborPx) const override;
  };
}

