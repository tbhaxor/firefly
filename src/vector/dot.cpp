#include <algorithm>

#include "firefly/vector.hpp"

namespace Firefly {
Real Vector::Dot(Vector const &_fvec) const {
  if (this->Size() != _fvec.Size()) {
    throw std::length_error("Size of two vectors must be equal.");
  }

  Vector dot{m_vec.size()};

  std::transform(m_vec.cbegin(), m_vec.cend(), _fvec.m_vec.cbegin(),
                 dot.m_vec.begin(),
                 [](Real const &a, Real const &b) { return a * b; });

  return dot.ElemSum();
}
} // namespace Firefly