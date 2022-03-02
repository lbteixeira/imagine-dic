#include <catch2/catch.hpp>
#include "hello.hpp"

TEST_CASE("Test case 1", "[tag1]"){
  SECTION("First section"){
    std::string expected("LT code starters!");
    REQUIRE(*imagine::sayHello() == expected);
  }
}

