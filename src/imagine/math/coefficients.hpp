#pragma once

#include <memory>
#include <vector>

namespace Imagine {
  namespace Math {

    class InterpBlockNode {
      public:
        InterpBlockNode();
        explicit InterpBlockNode(const std::vector<double>& coefficients);

        bool isEmpty() const;
        const std::vector<double>& getCoefficients() const;
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
