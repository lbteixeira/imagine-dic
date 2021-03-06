#include <catch2/catch.hpp>
#include <vector>
#include "coefficients.hpp"
#include "primitives.hpp"

using namespace Imagine;

TEST_CASE("Interpolation block node", "[blockNode]"){

  std::vector<double> coefficients = {1.0, 2.0, 3.0, 4.0, 5.0};

  InterpBlockNode node1;
  InterpBlockNode node2(coefficients);

  REQUIRE(node1.isEmpty());
  REQUIRE(!node2.isEmpty());

  node1.setCoefficients(coefficients);
  REQUIRE(!node1.isEmpty());

  std::vector<double> coefficients2 = node1.getCoefficients();
  REQUIRE(coefficients2 == coefficients);

  REQUIRE(coefficients2[0] == 1.0);
  REQUIRE(coefficients2[4] == 5.0);

}

TEST_CASE("Table of coefficients", "[table]"){

  CoefficientsTable lookupTable(5, 3);
  std::vector<double> ref;
  std::vector<double> ref2 = {1.1, 2.2, 3.3};
  Point p(2.213, 0.123);
  std::vector<double> coeffs = lookupTable.getCoefficientsAtPoint(p);

  // The vector of coefficients at the node is empty by default
  REQUIRE(lookupTable.isEmptyAtPoint(p));
  REQUIRE(coeffs == ref);

  lookupTable.setCoefficientsAtPoint(Point(2.214, 0.123), ref2);
  coeffs = lookupTable.getCoefficientsAtPoint(p);
  REQUIRE(!lookupTable.isEmptyAtPoint(Point(2.213, 0.123)));
  REQUIRE(coeffs == ref2);
  REQUIRE(coeffs[0] == 1.1);
  REQUIRE(coeffs[1] == 2.2);
  REQUIRE(coeffs[2] == 3.3);

  // Look-up table is not empty for any points in the range x = [2, 3[ and
  // y = [0, 1[, but continues to be empty elsewhere
  REQUIRE(!lookupTable.isEmptyAtPoint(Point(2.0, 0.0)));
  REQUIRE(!lookupTable.isEmptyAtPoint(Point(2.999, 0.0)));
  REQUIRE(!lookupTable.isEmptyAtPoint(Point(2.0, 0.999)));
  REQUIRE(!lookupTable.isEmptyAtPoint(Point(2.999, 0.999)));
  REQUIRE(!lookupTable.isEmptyAtPoint(Point(2.001, 0.99)));
  REQUIRE(!lookupTable.isEmptyAtPoint(Point(2.731, 0.0001)));
  REQUIRE(lookupTable.isEmptyAtPoint(Point(3.731, 0.0001)));
}

