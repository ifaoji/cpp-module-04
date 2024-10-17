#pragma once

#include "Brain.hpp"
#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);

  ~Dog();

  Dog &operator=(const Dog &rhs);

  void makeSound() const;
  const std::string &getType() const;

  void printBrainPtr() const;

private:
  Brain *brain;
};

#endif
