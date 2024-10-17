#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat default constructor called" << std::endl;

  type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal() {
  std::cout << "WrongCat copy constructor called" << std::endl;

  type = other.type;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  std::cout << "WrongCat copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  type = rhs.type;

  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "The wrong cat meows" << std::endl;
}

const std::string &WrongCat::getType() const { return type; }
