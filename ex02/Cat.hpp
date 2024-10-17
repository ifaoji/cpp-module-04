#pragma once

#include "Brain.hpp"
#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &other);

  ~Cat();

  Cat &operator=(const Cat &rhs);

  void makeSound() const;
  const std::string &getType() const;

  void printBrainPtr() const;

private:
  Brain *brain;
};

#endif
