#pragma once

#include <array>

namespace Imagine {
  namespace Math {
    class Interpolator {
      public:
        Interpolator(int, int);

        const std::array<int, 4> getPixelsCoordsAroundPoint(double, double) const;
        int numberPixelsX;
        int numberPixelsY;
    };
  }
}
