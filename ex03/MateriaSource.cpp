#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
  for (std::size_t i = 0; i < kTemplatesCapacity; i++) {
    templates_[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (std::size_t i = 0; i < kTemplatesCapacity; i++) {
    if (other.templates_[i] == NULL)
      break;

    templates_[i] = other.templates_[i]->clone();
  }
}

MateriaSource::~MateriaSource() {
  for (std::size_t i = 0; i < kTemplatesCapacity; i++) {
    delete templates_[i];
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  if (this == &rhs)
    return *this;

  for (std::size_t i = 0; i < kTemplatesCapacity; i++) {
    if (rhs.templates_[i] == NULL)
      break;

    templates_[i] = rhs.templates_[i]->clone();
  }

  return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
  std::size_t templates_len = 0;

  for (; templates_len < kTemplatesCapacity; templates_len++) {
    if (templates_[templates_len] == NULL)
      break;
  }

  if (templates_len == kTemplatesCapacity)
    return;

  templates_[templates_len] = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (std::size_t i = 0; i < kTemplatesCapacity; i++) {
    if (templates_[i] == NULL)
      break;

    if (templates_[i]->getType() == type)
      return templates_[i]->clone();
  }

  return NULL;
}
