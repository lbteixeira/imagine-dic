#include "interpolation.hpp"
#include <cassert>
#include <cstdlib>
#include <math.h>
#include <memory>
#include <vector>
#include <armadillo>

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


  /* BicubicInterpolator methods */
  BicubicInterpolator::BicubicInterpolator(std::size_t nX, std::size_t nY) :
      Interpolator(nX, nY){}

  BicubicInterpolator::~BicubicInterpolator(){}

  const std::vector<double>
  BicubicInterpolator::_calculateCoefficients(const vector_px& neighborPx){

    arma::mat A_inv(16, 16);
    arma::mat x(1, 16);
    arma::mat alpha(16, 1);
    std::vector<double> result;

    double f_0_0, f_1_0, f_0_1, f_1_1;
    double fx_0_0, fx_1_0, fx_0_1, fx_1_1;
    double fy_0_0, fy_1_0, fy_0_1, fy_1_1;
    double fxy_0_0, fxy_1_0, fxy_0_1, fxy_1_1;

    A_inv = { { 1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
              { 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
              {-3,  3,  0,  0, -2, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
              { 2, -2,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
              { 0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0},
              { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0},
              { 0,  0,  0,  0,  0,  0,  0,  0, -3,  3,  0,  0, -2, -1,  0,  0},
              { 0,  0,  0,  0,  0,  0,  0,  0,  2, -2,  0,  0,  1,  1,  0,  0},
              {-3,  0,  3,  0,  0,  0,  0,  0, -2,  0, -1,  0,  0,  0,  0,  0},
              { 0,  0,  0,  0, -3,  0,  3,  0,  0,  0,  0,  0, -2,  0, -1,  0},
              { 9, -9, -9,  9,  6,  3, -6, -3,  6, -6,  3, -3,  4,  2,  2,  1},
              {-6,  6,  6, -6, -3, -3,  3,  3, -4,  4, -2,  2, -2, -2, -1, -1},
              { 2,  0, -2,  0,  0,  0,  0,  0,  1,  0,  1,  0,  0,  0,  0,  0},
              { 0,  0,  0,  0,  2,  0, -2,  0,  0,  0,  0,  0,  1,  0,  1,  0},
              {-6,  6,  6, -6, -4, -2,  4,  2, -3,  3, -3,  3, -2, -1, -2, -1},
              { 4, -4, -4,  4,  2,  2, -2, -2,  2, -2,  2, -2,  1,  1,  1,  1}
    };

    f_0_0 = neighborPx[5][2];
    f_1_0 = neighborPx[6][2];
    f_0_1 = neighborPx[9][2];
    f_1_1 = neighborPx[10][2];

    fx_0_0 = double(neighborPx[6][2] - neighborPx[4][2])  / 2;
    fx_1_0 = double(neighborPx[7][2] - neighborPx[5][2])  / 2;
    fx_0_1 = double(neighborPx[10][2] - neighborPx[8][2]) / 2;
    fx_1_1 = double(neighborPx[11][2] - neighborPx[9][2]) / 2;

    fy_0_0 = double(neighborPx[9][2] - neighborPx[1][2])  / 2;
    fy_1_0 = double(neighborPx[10][2] - neighborPx[2][2]) / 2;
    fy_0_1 = double(neighborPx[13][2] - neighborPx[5][2]) / 2;
    fy_1_1 = double(neighborPx[14][2] - neighborPx[6][2]) / 2;

    fxy_0_0 = double(neighborPx[0][2] - neighborPx[2][2] + neighborPx[10][2] - neighborPx[8][2])   / 4;
    fxy_1_0 = double(neighborPx[1][2] - neighborPx[3][2] + neighborPx[11][2] - neighborPx[9][2])   / 4;
    fxy_0_1 = double(neighborPx[4][2] - neighborPx[6][2] + neighborPx[14][2] - neighborPx[12][2])  / 4;
    fxy_1_1 = double(neighborPx[5][2] - neighborPx[7][2] + neighborPx[15][2] - neighborPx[13][2])  / 4;

    x = {f_0_0, f_1_0, f_0_1, f_1_1, fx_0_0, fx_1_0, fx_0_1, fx_1_1, fy_0_0,
      fy_1_0, fy_0_1, fy_1_1, fxy_0_0, fxy_1_0, fxy_0_1, fxy_1_1};

    alpha = A_inv * x.t();

    for (arma::uword i=0; i<16; i++) {
      result.push_back(alpha(i));
    }

    return result;

  }

  double
  BicubicInterpolator::_interpolate(const Point<double>& p, const
      std::vector<double>& coefficients) const {

    double x = p.coordX - int(p.coordX);
    double y = p.coordY - int(p.coordY);
    double result = 0;

    // x and y can't be zero, because that would mean that point p is at an
    // integer pixel location, where no interpolation is required.
    assert(x != 0);
    assert(y != 0);

    result += coefficients[0];
    result += coefficients[1]*x;
    result += coefficients[2]*pow(x, 2);
    result += coefficients[3]*pow(x, 3);

    result += coefficients[4]*y;
    result += coefficients[5]*x*y;
    result += coefficients[6]*pow(x, 2)*y;
    result += coefficients[7]*pow(x, 3)*y;

    result += coefficients[8]*pow(y, 2);
    result += coefficients[9]*x*pow(y, 2);
    result += coefficients[10]*pow(x, 2)*pow(y, 2);
    result += coefficients[11]*pow(x, 3)*pow(y, 2);

    result += coefficients[12]*pow(y, 3);
    result += coefficients[13]*x*pow(y, 3);
    result += coefficients[14]*pow(x, 2)*pow(y, 3);
    result += coefficients[15]*pow(x, 3)*pow(y, 3);

    return result;
  }

}
