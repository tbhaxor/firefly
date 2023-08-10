#include <algorithm>
#include <functional>
#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Add(Vector const &_fvec) const {
  if (m_vec.size() != _fvec.m_vec.size()) {
    throw std::length_error("Rank of two vectors must be equal.");
  }

  Vector sum{m_vec.size()};

  std::transform(m_vec.cbegin(), m_vec.cend(), _fvec.m_vec.begin(),
                 sum.m_vec.begin(), std::plus<Real>());

  return sum;
}

Vector Vector::Add(Real const &_scalar) const {
  Vector sum{VectorType(m_vec.size(), _scalar)};

  std::transform(m_vec.cbegin(), m_vec.cend(), sum.m_vec.cbegin(),
                 sum.m_vec.begin(), std::plus<Real>());

  return sum;
}

Vector Vector::operator+(Real const &_scalar) const {
  return this->Add(_scalar);
}

Vector Vector::operator+(Vector const &_fvec) const { return this->Add(_fvec); }
} // namespace Firefly