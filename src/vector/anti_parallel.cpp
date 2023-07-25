#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::operator-() const { return this->Scale(-1); }
} // namespace Firefly