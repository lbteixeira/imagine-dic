#include "coefficients.hpp"
#include <vector>

namespace Imagine {
  namespace Math {
    /* InterpBlockNode methods */
    InterpBlockNode::InterpBlockNode(){_isEmpty = true; }

    InterpBlockNode::InterpBlockNode(const std::vector<double>& coefficients) :
      _isEmpty(false), _coefficients(coefficients){}

    bool
    InterpBlockNode::isEmpty() const { return _isEmpty; }

    void
    InterpBlockNode::setCoefficients(const std::vector<double>& coefficients){
      _coefficients = coefficients;
      _isEmpty = false;
    }

    const std::vector<double>&
    InterpBlockNode::getCoefficients() const{
      return _coefficients;
    }


    /* CoefficientsTable methods */
    CoefficientsTable::CoefficientsTable(std::size_t nX, std::size_t nY) :
      _sizeX(nX-1), _sizeY(nY-1),
      _lookupTable(std::make_unique<std::vector<InterpBlockNode>>((nX-1)*(nY-1))){
    }

    std::size_t
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
