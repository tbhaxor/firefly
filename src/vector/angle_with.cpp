#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {
Real Vector::AngleWith(Vector const &_fvec) const {
  if (this->IsZero() || _fvec.IsZero()) {
    throw std::logic_error("Can not find angle with zero vector.");
  }

  return std::acos(this->Dot(_fvec) / (this->Magnitude() * _fvec.Magnitude()));
}

} // namespace Firefly