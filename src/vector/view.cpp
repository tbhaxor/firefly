#include <sstream>

#include "firefly/vector.hpp"
namespace Firefly {
std::string Vector::View() const {
  std::stringstream ss;
  ss << "[";
  for (auto &el : m_vec) {
    ss << el << ", ";
  }
  ss << "\b\b]";
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, Firefly::Vector const &_fvec) {
  os << _fvec.View();
  return os;
}

} // namespace Firefly
