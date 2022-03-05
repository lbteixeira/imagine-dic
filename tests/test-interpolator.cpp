#include <array>
#include <catch2/catch.hpp>
#include "interpolation.hpp"

using namespace Imagine;

TEST_CASE("Interpolation", "[math]"){
  Math::Interpolator interp(5, 5);

  SECTION("Pixels around a given point"){
    std::array<int, 4> points;
    std::array<int, 4> expected;

    points = interp.getPixelsCoordsAroundPoint(0.7, 4.9);
    expected = {0, 1, 4, 5};
    REQUIRE(points == expected);

    // One of the points is an "integer"
    points = interp.getPixelsCoordsAroundPoint(2.0, 3.7);
    expected = {2, 3, 3, 4};
    REQUIRE(points == expected);

    // Both  points are "integers"
    points = interp.getPixelsCoordsAroundPoint(0.0, 0.0);
    expected = {0, 1, 0, 1};
    REQUIRE(points == expected);
  }

}

