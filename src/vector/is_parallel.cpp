#include <cmath>

#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsParallel(const Vector &_fvec) {
  if (this->Magnitude() == 0 || _fvec.Magnitude() == 0) {
    return true;
  }

  auto angle_radians = this->AngleWith(_fvec);
  return angle_radians == 0 || angle_radians == M_PI;
}
} // namespace Firefly