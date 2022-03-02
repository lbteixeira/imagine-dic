#include <array>
#include <catch2/catch.hpp>
#include "interpolation.hpp"

using namespace Imagine;

TEST_CASE("Interpolation", "[math]"){
  Math::Interpolator interp(100, 100);

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

  SECTION("Position of a point in the look-up list of coefficients"){

    Math::Interpolator interpSmall(5, 5);

    REQUIRE(interpSmall.positionInLookupForPoint(0.5, 0.5) == 0);
    REQUIRE(interpSmall.positionInLookupForPoint(1.5, 0.5) == 1);
    REQUIRE(interpSmall.positionInLookupForPoint(2.5, 0.5) == 2);
    REQUIRE(interpSmall.positionInLookupForPoint(3.5, 0.5) == 3);
    REQUIRE(interpSmall.positionInLookupForPoint(4.5, 0.5) == 4);


    REQUIRE(interpSmall.positionInLookupForPoint(0.5, 1.5) == 5);
    REQUIRE(interpSmall.positionInLookupForPoint(1.5, 1.5) == 6);
    REQUIRE(interpSmall.positionInLookupForPoint(2.5, 1.5) == 7);
    REQUIRE(interpSmall.positionInLookupForPoint(3.5, 1.5) == 8);
    REQUIRE(interpSmall.positionInLookupForPoint(4.5, 1.5) == 9);

    REQUIRE(interpSmall.positionInLookupForPoint(0.5, 2.5) == 10);
    REQUIRE(interpSmall.positionInLookupForPoint(1.5, 2.5) == 11);
    REQUIRE(interpSmall.positionInLookupForPoint(2.5, 2.5) == 12);
    REQUIRE(interpSmall.positionInLookupForPoint(3.5, 2.5) == 13);
    REQUIRE(interpSmall.positionInLookupForPoint(4.5, 2.5) == 14);

    REQUIRE(interpSmall.positionInLookupForPoint(0.5, 3.5) == 15);
    REQUIRE(interpSmall.positionInLookupForPoint(1.5, 3.5) == 16);
    REQUIRE(interpSmall.positionInLookupForPoint(2.5, 3.5) == 17);
    REQUIRE(interpSmall.positionInLookupForPoint(3.5, 3.5) == 18);
    REQUIRE(interpSmall.positionInLookupForPoint(4.5, 3.5) == 19);

    REQUIRE(interpSmall.positionInLookupForPoint(0.5, 4.5) == 20);
    REQUIRE(interpSmall.positionInLookupForPoint(1.5, 4.5) == 21);
    REQUIRE(interpSmall.positionInLookupForPoint(2.5, 4.5) == 22);
    REQUIRE(interpSmall.positionInLookupForPoint(3.5, 4.5) == 23);
    REQUIRE(interpSmall.positionInLookupForPoint(4.5, 4.5) == 24);
  }

}

