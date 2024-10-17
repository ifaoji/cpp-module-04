#pragma once

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal {
public:
  Animal();
  Animal(const Animal &other);

  ~Animal();

  Animal &operator=(const Animal &rhs);

  virtual void makeSound() const;
  virtual const std::string &getType() const;

protected:
  std::string type;
};

#endif
