#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog default constructor called" << std::endl;

  type = "Dog";
}

Dog::Dog(const Dog &other) : Animal() {
  std::cout << "Dog copy constructor called" << std::endl;

  type = other.type;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog &Dog::operator=(const Dog &rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  type = rhs.type;

  return *this;
}

void Dog::makeSound() const { std::cout << "The dog barks" << std::endl; }

const std::string &Dog::getType() const { return type; }
