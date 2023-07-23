#include <iostream>

#include "firefly/vector.hpp"

namespace Firefly {
std::unique_ptr<Vector> Vector::Subtract(Vector const &_fvec) const { return this->Add(*_fvec.Scale(-1)); }
std::unique_ptr<Vector> Vector::Subtract(Real const &_scalar) const { return this->Add(-_scalar); }

std::unique_ptr<Vector> Vector::operator-(Vector const &_fvec) const { return this->Subtract(_fvec); }
std::unique_ptr<Vector> Vector::operator-(Real const &_scalar) const { return this->Subtract(_scalar); }

std::unique_ptr<Vector> Vector::operator--() const { return this->Subtract(1); }
} // namespace Firefly