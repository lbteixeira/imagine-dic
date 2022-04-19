#include "interpolation.hpp"
#include <cmath>
#include <memory>
#include <tuple>
#include <vector>

typedef std::vector<std::array<int, 3>> vector_px;

namespace Imagine {
  /* Interpolator methods */
  Interpolator::Interpolator(std::size_t nX, std::size_t nY) :
      _lookupTable(nX, nY){}

  Interpolator::~Interpolator(){}

  double
  Interpolator::interpolate(const Point<double>& p,
      const vector_px& neighborPx) {

    std::vector<double> coeffs;
    if (!_lookupTable.isEmptyAtPoint(p)) {
      coeffs = _lookupTable.getCoefficientsAtPoint(p); }
    else {
      coeffs = _calculateCoefficients(neighborPx);
      _lookupTable.setCoefficientsAtPoint(p, coeffs);
    }

    return _interpolate(p, coeffs);
  }

  /* BilinearInterpolator methods */
  BilinearInterpolator::BilinearInterpolator(std::size_t nX, std::size_t nY) :
      Interpolator(nX, nY){}

  BilinearInterpolator::~BilinearInterpolator(){}

  const std::vector<double>
  BilinearInterpolator::_calculateCoefficients(const vector_px& neighborPx) {

    double f1, f2, f3, f4;

    f1 = neighborPx[0][2];
    f2 = neighborPx[1][2];
    f3 = neighborPx[2][2];
    f4 = neighborPx[3][2];

    std::vector<double> result = {f1, f2-f1, f3-f1, f4-f2-f3+f1};

    return result;
  }

  double
  BilinearInterpolator::_interpolate(const Point<double>& p,
      const std::vector<double>& coefficients) const {

    double x, y;

    x = p.coordX - std::floor(p.coordX);
    y = p.coordY - std::floor(p.coordY);

    if (p.coordX != 0 && x == 0) {
      x = p.coordX;
    }

    if (p.coordY != 0 && y == 0) {
      y = p.coordY;
    }

    return coefficients[0] + coefficients[1] * x +
           coefficients[2] * y + coefficients[3] * x * y;
  }

}
