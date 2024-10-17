#include <iostream>

#include "Animal.hpp"

Animal::Animal() : type("Anything") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal &Animal::operator=(const Animal &rhs) {
  std::cout << "Animal copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  type = rhs.type;

  return *this;
}

const std::string &Animal::getType() const { return type; }
