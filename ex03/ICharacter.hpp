#pragma once

#ifndef I_CHARACTER_HPP_
#define I_CHARACTER_HPP_

#include <string>

// This is needed because of double inclusion.
class AMateria;

#include "AMateria.hpp"

class ICharacter {
public:
  virtual ~ICharacter() {}

  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};

#endif
