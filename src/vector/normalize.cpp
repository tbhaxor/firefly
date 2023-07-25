#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Normalize() const { return this->Scale(1 / this->Magnitude()); }
} // namespace Firefly