#include <algorithm>
#include <cmath>
#include <cstddef>

#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsParallel(const Vector &_fvec) const {
  if (m_vec.size() != _fvec.m_vec.size()) {
    return false;
  }

  if (this->IsZero() || _fvec.IsZero() || *this == _fvec) {
    return true;
  }

  auto const ratio = m_vec[0] / _fvec.m_vec[0];
  for (size_t i = 1; i < m_vec.size(); i++) {
    if (m_vec[i] / _fvec.m_vec[i] != ratio) {
      return false;
    }
  }

  return true;
}
} // namespace Firefly