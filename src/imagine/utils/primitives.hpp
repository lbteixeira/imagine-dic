#pragma once

namespace Imagine {
  namespace Utils {
    struct Point{
      Point(double x, double y) : coordX(x), coordY(y){}
      double coordX;
      double coordY;
    };
  }
}
