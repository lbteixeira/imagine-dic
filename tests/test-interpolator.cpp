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

    std::vector<std::tuple<int, int, int>> neighborPx;
    neighborPx.reserve(4);
    neighborPx.emplace_back(std::make_tuple(14, 20, 91));
    neighborPx.emplace_back(std::make_tuple(15, 20, 210));
    neighborPx.emplace_back(std::make_tuple(15, 21, 95));
    neighborPx.emplace_back(std::make_tuple(14, 21, 162));

    auto result = interpolator.interpolate(p, neighborPx);
    auto expected = 146.1;

    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };

  SECTION("Point 2"){
    Point<double> p(123.37, 157.81);

    std::vector<std::tuple<int, int, int>> neighborPx;
    neighborPx.push_back(std::make_tuple(123, 157, 97));
    neighborPx.push_back(std::make_tuple(124, 157, 12));
    neighborPx.push_back(std::make_tuple(124, 158, 213));
    neighborPx.push_back(std::make_tuple(123, 158, 255));

    auto result = interpolator.interpolate(p, neighborPx);
    auto expected = 206.42;

    REQUIRE(std::abs(result - expected) < abs_tolerance);
  };
}

