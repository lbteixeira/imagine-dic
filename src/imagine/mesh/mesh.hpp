#pragma once

#include "primitives.hpp"
#include <tuple>
#include <vector>

namespace Imagine {
  /**
   * @brief An interface to the generation of the DIC mesh.
   *
   */
  class Mesh {
    public:
      virtual void generate() = 0;
      std::vector<Point<int>> getCalculationPoints() const;
      void setCalculationPoints(const std::vector<Point<int>>&);

    protected:
      Mesh();

    private:
      // TODO vector of pointers to points?
      std::vector<Point<int>*> _calculationPoints;
  };

  /**
   * @brief A class to represent a mesh with a rectangular shape.
   */
  class RectangularMesh : public Mesh {
    public:
      RectangularMesh();
      /**
       * A constructor for the mesh with a rectangular shape.
       *
       * @param diagonalLine Line defining the diagonal of the rectangle.
       * @param deltaPixels Discretization step in directions x and y,
       * respectively. Values in pixels.
       */
      RectangularMesh(const Line<int>& diagonalLine,
          const std::pair<int, int>& deltaPixels);

      void generate() override;

    private:
      Line<int> _diagonalLine;
      std::pair<int, int> _deltaPixels;
      RoiRange _roiRange;
  };

  class CircleMesh : public Mesh {
    public:
      CircleMesh(const Point<int>& centerPoint, double diameter,
          const std::pair<int, int>& deltaPixels);

      void generate() override;

    private:
      Point<int> _centerPoint;
      double _diameter;
  };
}
