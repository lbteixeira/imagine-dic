#include "interpolation.hpp"
#include <cassert>
#include <memory>
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

    double x = p.coordX - int(p.coordX);
    double y = p.coordY - int(p.coordY);

    // x and y can't be zero, because that would mean that point p is at an
    // integer pixel location, where no interpolation is required.
    assert(x != 0);
    assert(y != 0);

    return coefficients[0] + coefficients[1] * x +
           coefficients[2] * y + coefficients[3] * x * y;
  }

}
