#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsNormalized() const {
  return static_cast<int>(this->Magnitude()) == static_cast<int>(1);
}
} // namespace Firefly