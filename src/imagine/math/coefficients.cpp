#include "coefficients.hpp"
#include <vector>

namespace Imagine {
  namespace Math {
    InterpBlockNode::InterpBlockNode(){ _isEmpty = true; }

    InterpBlockNode::InterpBlockNode(const std::vector<double>& coefficients) :
      _isEmpty(false), _coefficients(coefficients){}

    bool InterpBlockNode::isEmpty() const { return _isEmpty; }

    void InterpBlockNode::setCoefficients(const std::vector<double>& coeffs){
      _coefficients = coeffs;
      _isEmpty = false;
    }

    const std::vector<double>& InterpBlockNode::getCoefficients() const{
      return _coefficients;
    }

  }
}
