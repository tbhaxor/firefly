#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsParallel(const Vector &_fvec) {
  if (this->Magnitude() == 0 || _fvec.Magnitude() == 0) {
    return true;
  }
  return this->AngleWith(_fvec) == 0;
}
} // namespace Firefly