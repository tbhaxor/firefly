#include "firefly/vector.hpp"

namespace Firefly {
std::unique_ptr<Vector> Vector::Cross(Vector const &_fvec) const {
  if (m_vec->size() != 3 || _fvec.m_vec->size() != 3) {
    throw std::invalid_argument("Both vectors must be three-dimensional.");
  }

  std::unique_ptr<Vector> cross = std::make_unique<Vector>(m_vec->size());

  cross->At(0) = m_vec->at(1) * _fvec.At(2) - m_vec->at(2) * _fvec.At(1);
  cross->At(1) = m_vec->at(2) * _fvec.At(0) - m_vec->at(0) * _fvec.At(2);
  cross->At(2) = m_vec->at(0) * _fvec.At(1) - m_vec->at(1) * _fvec.At(0);

  return cross;
}
} // namespace Firefly