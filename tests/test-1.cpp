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

  SECTION("Position of a point in the look-up list of coefficients"){

    REQUIRE(interp.positionInLookupForPoint(0.5, 0.5) == 0);
    REQUIRE(interp.positionInLookupForPoint(1.5, 0.5) == 1);
    REQUIRE(interp.positionInLookupForPoint(2.5, 0.5) == 2);
    REQUIRE(interp.positionInLookupForPoint(3.5, 0.5) == 3);
    REQUIRE(interp.positionInLookupForPoint(4.5, 0.5) == 4);


    REQUIRE(interp.positionInLookupForPoint(0.5, 1.5) == 5);
    REQUIRE(interp.positionInLookupForPoint(1.5, 1.5) == 6);
    REQUIRE(interp.positionInLookupForPoint(2.5, 1.5) == 7);
    REQUIRE(interp.positionInLookupForPoint(3.5, 1.5) == 8);
    REQUIRE(interp.positionInLookupForPoint(4.5, 1.5) == 9);

    REQUIRE(interp.positionInLookupForPoint(0.5, 2.5) == 10);
    REQUIRE(interp.positionInLookupForPoint(1.5, 2.5) == 11);
    REQUIRE(interp.positionInLookupForPoint(2.5, 2.5) == 12);
    REQUIRE(interp.positionInLookupForPoint(3.5, 2.5) == 13);
    REQUIRE(interp.positionInLookupForPoint(4.5, 2.5) == 14);

    REQUIRE(interp.positionInLookupForPoint(0.5, 3.5) == 15);
    REQUIRE(interp.positionInLookupForPoint(1.5, 3.5) == 16);
    REQUIRE(interp.positionInLookupForPoint(2.5, 3.5) == 17);
    REQUIRE(interp.positionInLookupForPoint(3.5, 3.5) == 18);
    REQUIRE(interp.positionInLookupForPoint(4.5, 3.5) == 19);

    REQUIRE(interp.positionInLookupForPoint(0.5, 4.5) == 20);
    REQUIRE(interp.positionInLookupForPoint(1.5, 4.5) == 21);
    REQUIRE(interp.positionInLookupForPoint(2.5, 4.5) == 22);
    REQUIRE(interp.positionInLookupForPoint(3.5, 4.5) == 23);
    REQUIRE(interp.positionInLookupForPoint(4.5, 4.5) == 24);
  }

}

