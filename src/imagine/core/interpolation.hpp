#pragma once

#include "coefficients.hpp"
#include <memory>
#include <tuple>
#include <vector>

typedef std::vector<std::tuple<int, int, int>> vector_px;

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

      virtual double
      _interpolate(const Point<double>& p,
                   const vector_px& neighborPx) const = 0;

    private:
      std::unique_ptr<CoefficientsTable> _lookupTable;
  };

  class BilinearInterpolator : public Interpolator {
    public:
      BilinearInterpolator(std::size_t nX, std::size_t nY);
      virtual ~BilinearInterpolator();

    protected:
      virtual double
      _interpolate(const Point<double>& p,
                   const vector_px& neighborPx) const override;
  };
}

