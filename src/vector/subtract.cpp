#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Subtract(Vector const &_fvec) const { return *this + -_fvec; }
Vector Vector::Subtract(Real const &_scalar) const { return *this + -_scalar; }

Vector Vector::operator-(Vector const &_fvec) const {
  return this->Subtract(_fvec);
}
Vector Vector::operator-(Real const &_scalar) const {
  return this->Subtract(_scalar);
}
} // namespace Firefly