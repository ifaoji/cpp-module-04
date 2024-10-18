#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat default constructor called" << std::endl;

  type = "Cat";
  brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal() {
  std::cout << "Cat copy constructor called" << std::endl;

  type = other.type;
  brain = new Brain(*other.brain);
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;

  delete brain;
}

Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "Cat copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  delete brain;

  type = rhs.type;
  brain = new Brain(*rhs.brain);

  return *this;
}

void Cat::makeSound() const { std::cout << "The cat meows" << std::endl; }

const std::string &Cat::getType() const { return type; }

void Cat::printBrainPtr() const {
  std::cout << "Cat brain ptr: " << brain << std::endl;
}
