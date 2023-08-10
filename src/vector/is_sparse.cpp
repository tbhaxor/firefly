#include <algorithm>
#include <stdexcept>

#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsSparse() const {
  if (m_vec.empty()) {
    throw std::length_error("Can't determine sparseness of empty vector");
  }
  auto const zero_count = std::count_if(m_vec.cbegin(), m_vec.cend(),
                                        [](Real const &v) { return v == 0; });
  return (m_vec.size() - zero_count) < zero_count;
}
} // namespace Firefly