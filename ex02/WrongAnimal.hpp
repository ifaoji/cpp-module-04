#pragma once

#ifndef WRONG_ANIMAL_HPP_
#define WRONG_ANIMAL_HPP_

#include <string>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);

  ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &rhs);

  void makeSound() const;
  const std::string &getType() const;

protected:
  std::string type;
};

#endif
