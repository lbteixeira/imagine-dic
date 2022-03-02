#pragma once

#include <array>

namespace Imagine {
  namespace Math {
    class Interpolator {
      public:
        Interpolator();

        const std::array<int, 4> getPixelsCoordsAroundPoint(double, double) const;
    };
  }
}
