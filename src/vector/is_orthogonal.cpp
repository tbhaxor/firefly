#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsOrthogonal(Vector const &_fvec) const {
  return this->Dot(_fvec) == 0;
}
} // namespace Firefly