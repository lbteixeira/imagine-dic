#include "interpolation.hpp"
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
      const vector_px& neighborPx) const{

    std::vector<double> coeffs;
    if (!_lookupTable.isEmptyAtPoint(p)) {
      coeffs = _lookupTable.getCoefficientsAtPoint(p); }
    else {
      coeffs = _calculateCoefficients(p, neighborPx);
    }

    double interpolated = 0;
    for (std::size_t i = 0; i < coeffs.size(); i++) {
      interpolated += coeffs[i]*neighborPx[i][2];
    }

    return interpolated;
  }

  /* BilinearInterpolator methods */
  BilinearInterpolator::BilinearInterpolator(std::size_t nX, std::size_t nY) :
      Interpolator(nX, nY){}

  BilinearInterpolator::~BilinearInterpolator(){}

  const std::vector<double>
  BilinearInterpolator::_calculateCoefficients(const Point<double>& p,
      const vector_px& neighborPx) const{

    double w1, w2, w3, w4;
    double x, x1, x2, y, y1, y2;

    x = p.coordX;
    y = p.coordY;

    x1 = neighborPx[0][0];
    x2 = neighborPx[1][0];
    y1 = neighborPx[0][1];
    y2 = neighborPx[2][1];

    w1 = (x2 - x)*(y2 - y);
    w2 = (x - x1)*(y2 - y);
    w3 = (x - x1)*(y - y1);
    w4 = (x2 - x)*(y - y1);

    std::vector<double> result = {w1, w2, w3, w4};

    return result;
  }
}
