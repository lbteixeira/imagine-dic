#include <catch2/catch.hpp>
#include <memory>
#include <tuple>
#include "interpolation.hpp"

using namespace Imagine;

TEST_CASE("Interpolation"){

  auto abs_tolerance = 0.01;

  BilinearInterpolator interpolator(500, 500);

  SECTION("Point 1"){
    Point<double> p(14.5, 20.2);

    std::vector<std::array<int,3>>
    neighborPx = {{14, 20, 91}, {15, 20, 210}, {15, 21, 95 }, {14, 21, 162}};

    auto result = interpolator.interpolate(p, neighborPx);
    auto expected = 146.1;

    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };

  SECTION("Point 2"){
    Point<double> p(123.37, 157.81);

    std::vector<std::array<int,3>>
    neighborPx = {{123, 157, 97}, {124, 157, 12}, {124, 158, 213}, {123, 158, 255}};

    auto result = interpolator.interpolate(p, neighborPx);
    auto expected = 206.42;

    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };
}

