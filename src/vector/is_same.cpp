#include <algorithm>

#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsSame(const Vector &_fvec) const {
  if (m_vec.size() != _fvec.m_vec.size())
    return false;

  return std::equal(m_vec.begin(), m_vec.end(), _fvec.m_vec.begin());
}

bool Vector::operator==(const Vector &_fvec) const {
  return this->IsSame(_fvec);
}
} // namespace Firefly