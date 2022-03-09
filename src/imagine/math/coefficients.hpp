#pragma once

#include <memory>
#include <vector>
#include "../utils/primitives.hpp"


namespace Imagine {
  namespace Math {
    /**
     *  @brief A class to represent interpolation block nodes.
     *
     *  The table of interpolation coefficients (\p CoefficientsTable) is
     *  composed of interpolation block nodes, that contain a flag to indicate
     *  if this block was already calculated and a vector with the
     *  corresponding coefficients.
     *
     *  An interpolation block is the 2D space surrounded by four pixels, where
     *  the sub-pixel calculations take place.
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
         * @param coefficients Vector of coefficients used for the
         * interpolation.
         */
        explicit InterpBlockNode(const std::vector<double>& coefficients);

        /**
         * @brief Returns true if the vector of coefficients is empty.
         */
        bool
        isEmpty() const;
        /**
         * @brief Returns the vector of coefficients.
         */
        const
        std::vector<double>& getCoefficients() const;
        /**
         * @brief Sets the vector of coefficients.
         * @param coefficients A vector of interpolation coefficients.
         */
        void
        setCoefficients(const std::vector<double>& coefficients);

      private:
        bool _isEmpty;
        std::vector<double> _coefficients;
    };

    /**
     * @brief A class to represent a table of interpolation coefficients.
     *
     * A table of interpolation coefficients is used to accelerate the
     * computations and to avoid redundant calculations. Once the coefficients
     * are calculated for a given interpolation block, they are stored in the
     * table and retrieved in case they are needed for another calculation
     * step.
     */
    class CoefficientsTable {
      public:
        /**
         * @brief Constructor used to define a new table of interpolation
         * coefficients.
         *
         * The table of coefficients is a one-dimensional vector with size
         * equal to (\p nX - 1)*(\p nY - 1).
         *
         * @param nX Number of pixels in the region of interest (ROI) in
         * direction x.
         * @param nX Number of pixels in the region of interest (ROI) in
         * direction y.
         *
         */
        CoefficientsTable(std::size_t nX, std::size_t nY);
        /**
         * @brief Returns true if the table is empty for a given subpixel
         * coordinate.
         *
         * The table is said to be empty at a given position if the
         * corresponding \p InterpBlockNode has an empty vector of
         * interpolation coefficients.
         *
         * The required input parameter is not the direct position at the
         * table, but the point with subpixel location.
         *
         * @param p Point at subpixel location.
         */
        bool
        isEmptyAtPoint(const Utils::Point<double>& p) const;
        /**
         * @brief Get the interpolation coefficients for a given subpixel
         * location.
         *
         * The required input parameter is not the direct position at the
         * table, but the point with subpixel location.
         *
         * @param p Point at subpixel location.
         */
        const std::vector<double>&
        getCoefficientsAtPoint(const Utils::Point<double>& p) const;
        /**
         * @brief Set the interpolation coefficients for a given subpixel
         * location.
         *
         * The required input parameter is not the direct position at the
         * table, but the point with subpixel location.
         *
         * @param p Point at subpixel location.
         * @param coeffs A vector of interpolation coefficients.
         */
        void
        setCoefficientsAtPoint(const Utils::Point<double>& p,
            const std::vector<double>& coeffs);

      private:
        std::size_t _sizeX, _sizeY;
        std::unique_ptr<std::vector<InterpBlockNode>> _lookupTable;

        std::size_t
        getPositionForPoint(const Utils::Point<double>& p) const;
    };
  }
}
