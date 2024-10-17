#include <iostream>

#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain copy constructor called" << std::endl;

  for (std::size_t i = 0; i < kIdeaCount; i++) {
    ideas[i] = other.ideas[i];
  }
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain &Brain::operator=(const Brain &rhs) {
  std::cout << "Brain copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  for (std::size_t i = 0; i < kIdeaCount; i++) {
    ideas[i] = rhs.ideas[i];
  }

  return *this;
}

void Brain::printIdeasPtr() const {
  std::cout << "Ideas Ptr: " << &ideas << std::endl;
}
