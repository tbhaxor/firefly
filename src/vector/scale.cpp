#include <algorithm>
#include <functional>

#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Scale(Real const &_scalar) const {
  Vector scaled{VectorType(m_vec.size(), _scalar)};

  std::transform(m_vec.cbegin(), m_vec.cend(), scaled.m_vec.cbegin(),
                 scaled.m_vec.begin(), std::multiplies<Real>());

  return scaled;
}

Vector Vector::operator*(Real const &_scalar) const {
  return this->Scale(_scalar);
}
} // namespace Firefly