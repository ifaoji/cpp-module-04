#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog default constructor called" << std::endl;

  type = "Dog";
  brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal() {
  std::cout << "Dog copy constructor called" << std::endl;

  type = other.type;
  brain = new Brain(*other.brain);
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;

  delete brain;
}

Dog &Dog::operator=(const Dog &rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  delete brain;

  type = rhs.type;
  brain = new Brain(*rhs.brain);

  return *this;
}

void Dog::makeSound() const { std::cout << "The dog barks" << std::endl; }

const std::string &Dog::getType() const { return type; }

void Dog::printBrainPtr() const {
  std::cout << "Dog brain ptr: " << brain << std::endl;
}
