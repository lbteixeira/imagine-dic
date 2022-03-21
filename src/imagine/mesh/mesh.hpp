#pragma once

#include "primitives.hpp"
#include <tuple>
#include <vector>

namespace Imagine {
  namespace Mesh {

    /**
     * @brief An interface to the generation of the DIC mesh.
     *
     */
    class Mesh {
      public:
        virtual void generate() = 0;
        std::vector<Utils::Point<int>> getCalculationPoints() const;
        void setCalculationPoints(const std::vector<Utils::Point<int>>&);

      protected:
        Mesh();

      private:
        // TODO vector of pointers to points?
        std::vector<Utils::Point<int>*> _calculationPoints;
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
        RectangularMesh(const Utils::Line<int>& diagonalLine,
            const std::pair<int, int>& deltaPixels);

        void generate() override;

      private:
        Utils::Line<int> _diagonalLine;
        std::pair<int, int> _deltaPixels;
        Utils::RoiRange _roiRange;
    };

    class CircleMesh : public Mesh {
      public:
        CircleMesh(const Utils::Point<int>& centerPoint, double diameter,
            const std::pair<int, int>& deltaPixels);

        void generate() override;

      private:
        Utils::Point<int> _centerPoint;
        double _diameter;
    };
  }
}
