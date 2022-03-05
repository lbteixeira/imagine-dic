#include "coefficients.hpp"
#include <vector>

namespace Imagine {
  namespace Math {
    InterpBlockNode::InterpBlockNode(){_isEmpty = true; }

    InterpBlockNode::InterpBlockNode(const std::vector<double>& coefficients) :
      _isEmpty(false), _coefficients(coefficients){}

    bool
    InterpBlockNode::isEmpty() const { return _isEmpty; }

    void
    InterpBlockNode::setCoefficients(const std::vector<double>& coeffs){
      _coefficients = coeffs;
      _isEmpty = false;
    }

    const std::vector<double>&
    InterpBlockNode::getCoefficients() const{
      return _coefficients;
    }

    // Builds a look-up table of interpolation blocks nodes with size
    // (nX-1)x(nY-1), and using the constructor without arguments as default
    CoefficientsTable::CoefficientsTable(unsigned int nX, unsigned int nY) :
      _sizeX(nX-1), _sizeY(nY-1),
      _lookupTable(std::make_unique<std::vector<InterpBlockNode>>((nX-1)*(nY-1))){
    }

    unsigned int
    CoefficientsTable::getPositionForPoint(double x, double y) const{
      return unsigned(int(y)) * _sizeX + unsigned(int(x));
    }

    bool
    CoefficientsTable::isEmptyAtPoint(double x, double y) const {
      auto position = getPositionForPoint(x, y);
      return _lookupTable->at(position).isEmpty();
    }

    const std::vector<double>&
    CoefficientsTable::getCoefficientsAtPoint(double x, double y) const {
      auto position = getPositionForPoint(x, y);
      return _lookupTable->at(position).getCoefficients();
    }

    void
    CoefficientsTable::setCoefficientsAtPoint(double x, double y,
    const std::vector<double>& coeffs){
      auto position = getPositionForPoint(x, y);
      _lookupTable->at(position).setCoefficients(coeffs);
    }

  }
}
