#include <algorithm>

#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Scale(Real const &_scalar) const {
  Vector scaled{m_vec};

  std::transform(scaled.m_vec.cbegin(), scaled.m_vec.cend(),
                 scaled.m_vec.begin(),
                 [&](Real const &_el) { return _el * _scalar; });

  return scaled;
}

Vector Vector::operator*(Real const &_scalar) const {
  return this->Scale(_scalar);
}
} // namespace Firefly