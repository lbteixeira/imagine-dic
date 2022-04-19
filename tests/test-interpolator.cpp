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

