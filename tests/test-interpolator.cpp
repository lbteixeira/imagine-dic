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

    SECTION("Point 3 - Located exactly at the upper left corner"){
      Point<double> p1(0, 0);
      double result = interpolator.interpolate(p1, neighborPx);
      double expected = 68;
      REQUIRE(std::abs(result - expected) < abs_tolerance);
    };

    SECTION("Point 4 - Located exactly at the lower right corner"){
      Point<double> p1(1, 1);
      double result = interpolator.interpolate(p1, neighborPx);
      double expected = 180;
      REQUIRE(std::abs(result - expected) < abs_tolerance);
    };
  };

}

