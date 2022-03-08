#pragma once

#include <memory>
#include <vector>

namespace Imagine {
  namespace Math {
    /**
     *  @brief A class to represent interpolation block nodes.
     *
     *  The table of interpolation coefficients (\p CoefficientsTable) is
     *  composed of interpolation block nodes, that contain a flag to indicate
     *  if this block was already calculated and a vector with the
     *  corresponding coefficients.
     */
    class InterpBlockNode {
      public:
        /**
         * Constructor used to define an empty node. Used the initialization of
         * a \p CoefficientsTable object.
         */
        InterpBlockNode();
        /**
         * Constructor used to define a non-empty node.
         * @param coefficients vector of coefficients used for the interpolation.
         */
        explicit InterpBlockNode(const std::vector<double>& coefficients);

        /**
         * @brief Returns true if the vector of coefficients is empty.
         */
        bool isEmpty() const;
        /**
         * @brief Returns the vector of coefficients.
         */
        const std::vector<double>& getCoefficients() const;
        /**
         * @brief Sets the vector of coefficients.
         * @param coefficients a vector of interpolation coefficients.
         */
        void setCoefficients(const std::vector<double>& coefficients);

      private:
        bool _isEmpty;
        std::vector<double> _coefficients;
    };

    class CoefficientsTable {
      public:
        CoefficientsTable(std::size_t nX, std::size_t nY);
        bool isEmptyAtPoint(double x, double y) const;
        const std::vector<double>& getCoefficientsAtPoint(double x, double y) const;
        void setCoefficientsAtPoint(double x, double y, const std::vector<double>& coeffs);

      private:
        std::size_t _sizeX, _sizeY;
        std::unique_ptr<std::vector<InterpBlockNode>> _lookupTable;

        std::size_t getPositionForPoint(double x, double y) const;
    };
  }
}
