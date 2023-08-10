#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {

Real Vector::At(std::size_t idx) const {
  // negative error will be underflown because of unsigned
  if (idx >= m_vec.size()) {
    throw std::length_error(
        "Index out of range. Requested index: " + std::to_string(idx) +
        ", Vector size: " + std::to_string(m_vec.size()));
  }

  return m_vec[idx];
}

Real &Vector::At(std::size_t idx) {
  // negative error will be underflown because of unsigned
  if (idx >= m_vec.size()) {
    throw std::length_error(
        "Index out of range. Requested index: " + std::to_string(idx) +
        ", Vector size: " + std::to_string(m_vec.size()));
  }

  return m_vec[idx];
}

Real Vector::operator[](std::size_t idx) const { return this->At(idx); }

Real &Vector::operator[](std::size_t idx) { return this->At(idx); }
} // namespace Firefly