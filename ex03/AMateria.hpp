#pragma once

#ifndef A_MATERIA_HPP_
#define A_MATERIA_HPP_

#include <string>

// This is needed because of double inclusion.
class ICharacter;

#include "ICharacter.hpp"

class AMateria {
public:
  AMateria();
  AMateria(const std::string &type);
  AMateria(const AMateria &other);

  virtual ~AMateria();

  AMateria &operator=(const AMateria &rhs);

  const std::string &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target) = 0;

protected:
  std::string type;
};

#endif
