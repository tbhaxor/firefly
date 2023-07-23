#include <algorithm>

#include "firefly/vector.hpp"

namespace Firefly {
std::unique_ptr<Vector> Vector::Scale(Real const &_scalar) const {
  std::unique_ptr<Vector> scaled = std::make_unique<Vector>(*this);

  std::transform(scaled->m_vec->cbegin(), scaled->m_vec->cend(),
                 scaled->m_vec->begin(),
                 [&](Real const &_el) { return _el * _scalar; });

  return scaled;
}

std::unique_ptr<Vector> Vector::operator*(Real const &_scalar) const {
  return this->Scale(_scalar);
}
} // namespace Firefly