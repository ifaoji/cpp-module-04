#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat default constructor called" << std::endl;

  type = "Cat";
}

Cat::Cat(const Cat &other) : Animal() {
  std::cout << "Cat copy constructor called" << std::endl;

  type = other.type;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "Cat copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  type = rhs.type;

  return *this;
}

void Cat::makeSound() const { std::cout << "The cat meows" << std::endl; }

const std::string &Cat::getType() const { return type; }
