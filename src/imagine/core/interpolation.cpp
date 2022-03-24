#include "interpolation.hpp"
#include <memory>
#include <tuple>

typedef std::vector<std::tuple<int, int, int>> vector_px;

namespace Imagine {
  /* Interpolator methods */
  Interpolator::Interpolator(std::size_t nX, std::size_t nY) :
      _lookupTable(std::make_unique<CoefficientsTable>(nX, nY)){}

  Interpolator::~Interpolator(){}

  double
  Interpolator::interpolate(const Point<double>& p,
                            const vector_px& neighborPx) const{
    return _interpolate(p, neighborPx);
  }

  /* BilinearInterpolator methods */
  BilinearInterpolator::BilinearInterpolator(std::size_t nX, std::size_t nY) :
      Interpolator(nX, nY){}

  BilinearInterpolator::~BilinearInterpolator(){}

  double
  BilinearInterpolator::_interpolate(const Point<double>& p,
                                     const vector_px& neighborPx) const{

    double w1, w2, w3, w4;
    double p1, p2, p3, p4;
    double x, x1, x2, y, y1, y2;

    x = p.coordX;
    y = p.coordY;
    std::tie(x1, y1, p1) = neighborPx[0];
    std::tie(x2, y1, p2) = neighborPx[1];
    std::tie(x2, y2, p3) = neighborPx[2];
    std::tie(x1, y2, p4) = neighborPx[3];

    w1 = (x2 - x)*(y2 - y);
    w2 = (x - x1)*(y2 - y);
    w3 = (x - x1)*(y - y1);
    w4 = (x2 - x)*(y - y1);

    return p1*w1 + p2*w2 + p3*w3 + p4*w4;
  }
}
