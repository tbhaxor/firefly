#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsNormalized() { return this->Magnitude() == 1; }
} // namespace Firefly