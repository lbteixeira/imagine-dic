#include <array>
#include <catch2/catch.hpp>
#include "interpolation.hpp"

using namespace Imagine;

TEST_CASE("Interpolation", "[math]"){
  Math::Interpolator interp;

  SECTION("Pixels around a given point"){
    std::array<int, 4> points;
    std::array<int, 4> expected;

    points = interp.getPixelsCoordsAroundPoint(0.7, 10.9);
    expected = {0, 1, 10, 11};
    REQUIRE(points == expected);

    // One of the points is an "integer"
    points = interp.getPixelsCoordsAroundPoint(1000.0, 134.7);
    expected = {1000, 1001, 134, 135};
    REQUIRE(points == expected);

    // Both  points are "integers"
    points = interp.getPixelsCoordsAroundPoint(0.0, 0.0);
    expected = {0, 1, 0, 1};
    REQUIRE(points == expected);
  }
}

