#include <functional>
#include <numeric>

#include "firefly/vector.hpp"

namespace Firefly {

Real Vector::ElemSum() const {
  return std::accumulate(m_vec.cbegin(), m_vec.cend(), 0x0);
}
} // namespace Firefly