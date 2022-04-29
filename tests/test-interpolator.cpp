#include <catch2/catch.hpp>
#include <memory>
#include "interpolation.hpp"

using namespace Imagine;

// The expected results for these tests were taken from GNU Octave's interp2
// function.

TEST_CASE("Bilinear interpolation"){

  double abs_tolerance = 0.01;
  BilinearInterpolator interpolator(500, 500);

  SECTION("Points in the unit square"){
    std::vector<std::array<int,3>>
    neighborPx = {{0, 0, 68}, {1, 0, 71}, {0, 1, 209}, {1, 1, 180}};

    SECTION("Point 1"){
      Point<double> p1(0.5, 0.2);
      double result = interpolator.interpolate(p1, neighborPx);
      double expected = 94.5;
      REQUIRE(std::abs(result - expected) < abs_tolerance);
    };

    SECTION("Point 2"){
      Point<double> p1(0.2, 0.5);
      double result = interpolator.interpolate(p1, neighborPx);
      double expected = 135.9;
      REQUIRE(std::abs(result - expected) < abs_tolerance);
    };
  };

  SECTION("Points NOT in the unit square"){
    std::vector<std::array<int,3>>
    neighborPx = {{10, 50, 68}, {11, 50, 71}, {10, 51, 209}, {11, 51, 180}};

    SECTION("Point 1"){
      Point<double> p1(10.5, 50.2);
      double result = interpolator.interpolate(p1, neighborPx);
      double expected = 94.5;
      REQUIRE(std::abs(result - expected) < abs_tolerance);
    };

    SECTION("Point 2"){
      Point<double> p1(10.2, 50.5);
      double result = interpolator.interpolate(p1, neighborPx);
      double expected = 135.9;
      REQUIRE(std::abs(result - expected) < abs_tolerance);
    };
  };
}

TEST_CASE("Bicubic interpolation"){

  double abs_tolerance = 0.01;
  BicubicInterpolator interpolator(500, 500);

  std::vector<std::array<int,3>>
  neighborPx = {{0, 0, 97},  {1, 0, 12},  {2, 0, 15},  {3, 0, 22},
                {0, 1, 208}, {1, 1, 68},  {2, 1, 71},  {3, 1, 255},
                {0, 2, 71},  {1, 2, 209}, {2, 2, 180}, {3, 2, 0},
                {0, 3, 36},  {1, 3, 44},  {2, 3, 27},  {3, 3, 3}};

  SECTION("Point 1"){
    Point<double> p1(1.5, 1.2);
    double result = interpolator.interpolate(p1, neighborPx);
    double expected = 79.835;
    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };

  SECTION("Point 2"){
    Point<double> p1(1.2, 1.5);
    double result = interpolator.interpolate(p1, neighborPx);
    double expected = 150.40;
    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };

}

