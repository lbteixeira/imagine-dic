#pragma once

namespace Imagine {
  namespace Utils {
    template<typename T>
    struct Point{
      Point(T x, T y) : coordX(x), coordY(y){}
      T coordX;
      T coordY;
    };
  }
}
