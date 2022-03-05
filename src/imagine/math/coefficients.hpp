#pragma once

#include <memory>
#include <vector>

namespace Imagine {
  namespace Math {

    class InterpBlockNode {
      public:
        InterpBlockNode();
        explicit InterpBlockNode(const std::vector<double>&);
        InterpBlockNode(const std::vector<double>&, bool);

        bool isEmpty() const;
        const std::vector<double>& getCoefficients() const;
        void setCoefficients(const std::vector<double>&);

      private:
        bool _isEmpty;
        std::vector<double> _coefficients;

    };

    class CoefficientsTable {
      public:
        CoefficientsTable(unsigned int, unsigned int);
        bool isEmptyAtPoint(double, double) const;
        const std::vector<double>& getCoefficientsAtPoint(double, double) const;

      private:
        unsigned int _sizeX, _sizeY;
        std::unique_ptr<std::vector<InterpBlockNode>> _lookupTable;

        unsigned int getPositionForPoint(double, double) const;
    };
  }
}
