#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() {
  name_ = "Anonymous";

  for (std::size_t i = 0; i < kInventoryCapacity; i++) {
    inventory_[i] = NULL;
  }
}

Character::Character(const std::string &name) {
  name_ = name;

  for (std::size_t i = 0; i < kInventoryCapacity; i++) {
    inventory_[i] = NULL;
  }
}

Character::Character(const Character &other) {
  name_ = other.name_;

  for (std::size_t i = 0; i < kInventoryCapacity; i++) {
    if (other.inventory_[i] == NULL)
      break;

    inventory_[i] = other.inventory_[i]->clone();
  }
}

Character::~Character() {
  for (std::size_t i = 0; i < kInventoryCapacity; i++) {
    delete inventory_[i];
  }
}

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs)
    return *this;

  name_ = rhs.name_;

  for (std::size_t i = 0; i < kInventoryCapacity; i++) {
    if (rhs.inventory_[i] == NULL)
      break;

    delete inventory_[i];

    inventory_[i] = rhs.inventory_[i]->clone();
  }

  return *this;
}

std::string const &Character::getName() const { return name_; }

void Character::equip(AMateria *materia) {
  std::size_t inventory_len = 0;

  for (; inventory_len < kInventoryCapacity; inventory_len++) {
    if (inventory_[inventory_len] == NULL)
      break;
  }

  if (inventory_len == kInventoryCapacity)
    return;

  inventory_[inventory_len] = materia;
}

void Character::unequip(int idx) {
  if (idx < 0 || (std::size_t)idx >= kInventoryCapacity)
    return;

  if (inventory_[idx] == NULL)
    return;

  inventory_[idx] = NULL;

  for (std::size_t i = idx; i < kInventoryCapacity - 1; i++) {
    inventory_[i] = inventory_[i + 1];
  }
  inventory_[kInventoryCapacity - 1] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || (std::size_t)idx >= kInventoryCapacity)
    return;

  AMateria *materia = inventory_[idx];

  if (materia == NULL)
    return;

  materia->use(target);
}
