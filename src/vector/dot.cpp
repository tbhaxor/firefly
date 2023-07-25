#include <iostream>
#include <numeric>

#include "firefly/vector.hpp"

namespace Firefly {
Real Vector::Dot(Vector const &_fvec) const {
  if (this->Size() != _fvec.Size()) {
    throw std::length_error("Size of two vectors must be equal.");
  }

  return std::inner_product(m_vec.cbegin(), m_vec.cend(), _fvec.m_vec.cbegin(),
                            static_cast<Real>(0));
}
} // namespace Firefly