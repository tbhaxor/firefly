#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Normalize() const {
  if (this->IsZero()) {
    throw std::logic_error("Zero vector can't be normalized");
  }

  return this->Scale(1 / this->Magnitude());
}
} // namespace Firefly