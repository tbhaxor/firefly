#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Cross(Vector const &_fvec) const {
  if (m_vec.size() != 3 || _fvec.m_vec.size() != 3) {
    throw std::invalid_argument("Both vectors must be three-dimensional.");
  }

  Vector cross{m_vec.size()};

  cross[0] = m_vec[1] * _fvec[2] - m_vec[2] * _fvec[1];
  cross[1] = m_vec[2] * _fvec[0] - m_vec[0] * _fvec[2];
  cross[2] = m_vec[0] * _fvec[1] - m_vec[1] * _fvec[0];

  return cross;
}
} // namespace Firefly