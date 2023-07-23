#include "firefly/vector.hpp"

namespace Firefly {
Real Vector::ParallelogramArea(Vector const &_fvec) const {
  return this->Cross(_fvec)->Magnitude();
}

Real Vector::TriangleArea(Vector const &_fvec) const {
  return this->ParallelogramArea(_fvec) / 2;
}
} // namespace Firefly