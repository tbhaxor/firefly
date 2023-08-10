#include <algorithm>

#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsSame(Vector const &_fvec) const {
  if (m_vec.size() != m_vec.size()) {
    return false;
  }

  return std::equal(m_vec.cbegin(), m_vec.cend(), _fvec.m_vec.cbegin());
}

bool Vector::operator==(Vector const &_fvec) const {
  return this->IsSame(_fvec);
}

} // namespace Firefly