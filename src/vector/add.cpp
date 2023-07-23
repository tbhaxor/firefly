#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {
std::unique_ptr<Vector> Vector::Add(Vector const &_fvec) const {
  if (m_vec->size() != _fvec.m_vec->size()) {
    throw std::length_error("Rank of two vectors must be equal.");
  }

  std::unique_ptr<Vector> sum = std::make_unique<Vector>(_fvec);

  for (std::size_t i = 0; i < m_vec->size(); i++) {
    sum->At(i) += m_vec->at(i);
  }

  return sum;
}

std::unique_ptr<Vector> Vector::Add(Real const &_scalar) const {
  std::unique_ptr<Vector> sum = std::make_unique<Vector>(*this);

  std::transform(sum->m_vec->cbegin(), sum->m_vec->cend(), sum->m_vec->begin(), [&](Real const &_el) { return _el + _scalar; });

  return sum;
}

std::unique_ptr<Vector> Vector::operator+(Real const &_scalar) const { return this->Add(_scalar); }

std::unique_ptr<Vector> Vector::operator+(Vector const &_fvec) const { return this->Add(_fvec); }

std::unique_ptr<Vector> Vector::operator++() const { return this->Add(1); }
} // namespace Firefly