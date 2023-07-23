#include "firefly/vector.hpp"

namespace Firefly {
std::unique_ptr<Vector> Vector::Normalize() const {
  return this->Scale(1 / this->Magnitude());
}
} // namespace Firefly