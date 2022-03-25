#include <catch2/catch.hpp>
#include <memory>
#include <tuple>
#include "interpolation.hpp"

using namespace Imagine;

TEST_CASE("Interpolation"){

  auto abs_tolerance = 0.01;

  BilinearInterpolator interpolator(500, 500);

  SECTION("Point 1"){
    Point<double> p1(0.5, 0.2);

    std::vector<std::array<int,3>>
    neighborPx = {{0, 0, 91}, {1, 0, 210}, {1, 1, 95}, {0, 1, 162}};

    auto result = interpolator.interpolate(p1, neighborPx);
    auto expected = 146.1;

    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };

  SECTION("Point 2"){
    Point<double> p1(123.37, 157.81);
    Point<double> p2(123.98, 157.41);

    std::vector<std::array<int,3>>
    neighborPx = {{123, 157, 97}, {124, 157, 12}, {124, 158, 213}, {123, 158, 255}};

    auto result = interpolator.interpolate(p1, neighborPx);
    auto expected = 206.42;

    REQUIRE(std::abs(result - expected) < abs_tolerance);

    result = interpolator.interpolate(p2, neighborPx);
    expected = 95.76;

    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };
}

