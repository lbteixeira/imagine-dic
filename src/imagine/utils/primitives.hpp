#pragma once

namespace Imagine {
  namespace Utils {
    template<typename T>
    struct Point{
      Point(T x, T y) : coordX(x), coordY(y){}
      T coordX;
      T coordY;
    };

    template<typename T>
    struct Pixel{
      Pixel(Point<int> p, T intensity) : point(p), intensity(intensity){}
      Point<int> point;
      T intensity;
    };
  }
}
