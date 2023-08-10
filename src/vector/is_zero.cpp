#include <algorithm>

#include "firefly/vector.hpp"

namespace Firefly {
bool Vector::IsZero() const {
  return std::all_of(m_vec.cbegin(), m_vec.cend(),
                     [](Real const &_el) { return _el == 0; });
}
} // namespace Firefly