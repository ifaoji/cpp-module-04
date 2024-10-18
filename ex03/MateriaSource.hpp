#pragma once

#ifndef MATERIA_SOURCE_HPP_
#define MATERIA_SOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);

  ~MateriaSource();

  MateriaSource &operator=(const MateriaSource &rhs);

  void learnMateria(AMateria *);
  AMateria *createMateria(const std::string &type);

private:
  const static std::size_t kTemplatesCapacity = 4;

  AMateria *templates_[kTemplatesCapacity];
};

#endif
