#include <cmath>

#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsParallel(const Vector &_fvec) {
  if (this->Magnitude() == 0 || _fvec.Magnitude() == 0) {
    return true;
  }

  // convert angle from radians to degrees
  auto angle_degrees = this->AngleWith(_fvec) * (180 / M_PI);

  return std::round(angle_degrees) == 90 || std::round(angle_degrees) == 180;
}
} // namespace Firefly