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
      interpolate(const Point<double>& p, const vector_px& neighborPx);

    protected:
      Interpolator(std::size_t nX, std::size_t nY);

      CoefficientsTable _lookupTable;

      virtual const std::vector<double>
      _calculateCoefficients(const vector_px& neighborPx) = 0;

      virtual double
      _interpolate(const Point<double>& p,
          const std::vector<double>& coefficients) const = 0;
  };

  class BilinearInterpolator : public Interpolator {
    public:
      BilinearInterpolator(std::size_t nX, std::size_t nY);
      virtual ~BilinearInterpolator();

    protected:
      virtual const std::vector<double>
      _calculateCoefficients(const vector_px& neighborPx) override;

      virtual double
      _interpolate(const Point<double>& p,
          const std::vector<double>& neighborPx) const override;
  };
}

