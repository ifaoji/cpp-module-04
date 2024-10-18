#pragma once

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character();
  Character(const std::string &name);
  Character(const Character &other);

  ~Character();

  Character &operator=(const Character &rhs);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  const static std::size_t kInventoryCapacity = 4;

  std::string name_;
  AMateria *inventory_[kInventoryCapacity];
};

#endif
