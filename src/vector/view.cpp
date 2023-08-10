#include <sstream>

#include "firefly/vector.hpp"

namespace Firefly {
std::string Vector::View() const {
  std::stringstream ss;
  ss << "[";

  if (!m_vec.empty()) {
    // Print the first element without a leading comma
    ss << m_vec[0];

    // Print the remaining elements with a leading comma
    for (size_t i = 1; i < m_vec.size(); ++i) {
      ss << ", " << m_vec[i];
    }
  }

  ss << "]";
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, Firefly::Vector const &_fvec) {
  os << _fvec.View();
  return os;
}

} // namespace Firefly
