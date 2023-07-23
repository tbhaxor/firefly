#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {

Real Vector::At(std::size_t idx) const {
  if (idx >= m_vec->size()) {
    throw std::out_of_range("Index out of range. Requested index: " + std::to_string(idx) +
			    ", Vector size: " + std::to_string(m_vec->size()));
  }

  return m_vec->at(idx);
}

Real &Vector::At(std::size_t idx) {
  if (idx >= m_vec->size()) {
    m_vec->resize(idx + 1);
  }

  return m_vec->at(idx);
}

Real Vector::operator[](std::size_t idx) const { return this->At(idx); }

Real &Vector::operator[](std::size_t idx) { return this->At(idx); }
} // namespace Firefly