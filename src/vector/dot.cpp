#include "firefly/vector.hpp"

namespace Firefly {
Real Vector::Dot(Vector const &_fvec) const {
  if (this->Size() != _fvec.Size()) {
    throw std::length_error("Size of two vectors must be equal.");
  }

  std::unique_ptr<Vector> dot = std::make_unique<Vector>(*_fvec.m_vec);

  for (std::size_t i = 0; i < m_vec->size(); i++) {
    dot->At(i) *= m_vec->at(i);
  }

  return dot->ElemSum();
}
} // namespace Firefly