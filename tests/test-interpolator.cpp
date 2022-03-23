#include <catch2/catch.hpp>
#include <memory>
#include "interpolation.hpp"

using namespace Imagine;

TEST_CASE("Interpolation"){
  std::unique_ptr<Interpolator> interpolator = std::make_unique<BilinearInterpolator>();
}

