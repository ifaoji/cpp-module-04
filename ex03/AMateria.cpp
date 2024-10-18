#include "AMateria.hpp"

AMateria::AMateria() { type = "Unknown"; }

AMateria::AMateria(const std::string &type) { AMateria::type = type; }

AMateria::AMateria(const AMateria &other) { type = other.type; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this == &rhs)
    return *this;

  type = rhs.type;

  return *this;
}

const std::string &AMateria::getType() const { return type; }
