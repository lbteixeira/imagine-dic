#include "interpolation.hpp"
#include <memory>

namespace Imagine {
  Interpolator::Interpolator(std::size_t nX, std::size_t nY) :
      _lookupTable(std::make_unique<CoefficientsTable>(nX, nY)){}

  Interpolator::~Interpolator(){}

  BilinearInterpolator::BilinearInterpolator(std::size_t nX, std::size_t nY) :
      Interpolator(nX, nY){}

  BilinearInterpolator::~BilinearInterpolator(){}

  double
  BilinearInterpolator::interpolate(Point<double> p) const{
    return p.coordX;
  }
}
