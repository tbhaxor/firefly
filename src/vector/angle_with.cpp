#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {
Real Vector::AngleWith(Vector const &_fvec) const {
  auto angle_radians =
      std::acos(this->Dot(_fvec) / (this->Magnitude() * _fvec.Magnitude()));
  if (std::isnan(angle_radians)) {
    throw std::domain_error("Can not find angle with zero vector.");
  }

  return angle_radians;
}

} // namespace Firefly