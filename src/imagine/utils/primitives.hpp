#pragma once

namespace Imagine {
  namespace Utils {
    template<typename T>
    struct Point{
      Point(T x, T y) : coordX(x), coordY(y){}
      T coordX, coordY;
    };

    template<typename T>
    struct Line{
      Line(Point<T> p1, Point<T> p2) : p1(p1), p2(p2){};
      Point<T> p1, p2;
    };

    template<typename T>
    struct Pixel{
      Pixel(Point<int> p, T intensity) : point(p), intensity(intensity){}
      Point<int> point;
      T intensity;
    };

    struct RoiRange{
      RoiRange(int xMin, int xMax, int yMin, int yMax) :
        xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax){}

      int xMin, xMax, yMin, yMax;
    };
  }
}
