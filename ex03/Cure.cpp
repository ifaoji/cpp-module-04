#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &rhs) {
  if (this == &rhs)
    return *this;

  AMateria::operator=(rhs);

  return *this;
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
