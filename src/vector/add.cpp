#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {
Vector Vector::Add(Vector const &_fvec) const {
  if (m_vec.size() != _fvec.m_vec.size()) {
    throw std::length_error("Rank of two vectors must be equal.");
  }

  Vector sum{_fvec};

  std::transform(m_vec.cbegin(), m_vec.cend(), sum.m_vec.begin(),
                 sum.m_vec.begin(),
                 [](Real const &a, Real const &b) { return a + b; });

  return sum;
}

Vector Vector::Add(Real const &_scalar) const {
  Vector sum{m_vec};

  std::transform(m_vec.cbegin(), sum.m_vec.cend(), sum.m_vec.begin(),
                 [&](Real const &_el) { return _el + _scalar; });

  return sum;
}

Vector Vector::operator+(Real const &_scalar) const {
  return this->Add(_scalar);
}

Vector Vector::operator+(Vector const &_fvec) const { return this->Add(_fvec); }

Vector Vector::operator++() const { return this->Add(1); }
} // namespace Firefly