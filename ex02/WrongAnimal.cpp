#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Anything") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  type = rhs.type;

  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "You can now hear the sound of a wrong animal" << std::endl;
}

const std::string &WrongAnimal::getType() const { return type; }
