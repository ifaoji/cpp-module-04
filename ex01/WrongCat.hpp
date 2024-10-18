#pragma once

#ifndef WRONG_CAT_HPP_
#define WRONG_CAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &other);

  ~WrongCat();

  WrongCat &operator=(const WrongCat &rhs);

  void makeSound() const;
  const std::string &getType() const;
};

#endif
