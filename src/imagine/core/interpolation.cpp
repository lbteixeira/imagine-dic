#include "interpolation.hpp"
#include <memory>

namespace Imagine {
  Interpolator::Interpolator(){}
  Interpolator::~Interpolator(){}

  BilinearInterpolator::BilinearInterpolator(){}
  BilinearInterpolator::~BilinearInterpolator(){}

  double
  BilinearInterpolator::interpolate(Point<double> p) const{
    return p.coordX;
  }
}
