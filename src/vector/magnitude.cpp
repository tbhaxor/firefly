#include <cmath>

#include "firefly/vector.hpp"

namespace Firefly {
Real Vector::Magnitude() const { return static_cast<Real>(std::sqrt(this->Dot(*this))); }
} // namespace Firefly