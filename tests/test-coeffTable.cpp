#include <catch2/catch.hpp>
#include <vector>
#include "coefficients.hpp"

using namespace Imagine;

TEST_CASE("Interpolation block node", "[blockNode]"){

  std::vector<double> coefficients = {1.0, 2.0, 3.0, 4.0, 5.0};

  Math::InterpBlockNode node1;
  Math::InterpBlockNode node2(coefficients);

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

  Math::CoefficientsTable lookupTable(5, 3);
  std::vector<double> ref;
  std::vector<double> ref2 = {1.1, 2.2, 3.3};
  std::vector<double> coeffs = lookupTable.getCoefficientsAtPoint(2.213, 0.123);

  // The vector of coefficients at the node is empty by default
  REQUIRE(lookupTable.isEmptyAtPoint(2.213, 0.123));
  REQUIRE(coeffs == ref);

  lookupTable.setCoefficientsAtPoint(2.214, 0.123, ref2);
  coeffs = lookupTable.getCoefficientsAtPoint(2.213, 0.123);
  REQUIRE(!lookupTable.isEmptyAtPoint(2.213, 0.123));
  REQUIRE(coeffs == ref2);
  REQUIRE(coeffs[0] == 1.1);
  REQUIRE(coeffs[1] == 2.2);
  REQUIRE(coeffs[2] == 3.3);

}

