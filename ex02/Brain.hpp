#pragma once

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <string>

class Brain {
public:
  Brain();
  Brain(const Brain &other);

  ~Brain();

  Brain &operator=(const Brain &rhs);

  void printIdeasPtr() const;

private:
  const static std::size_t kIdeaCount = 100;

  std::string ideas[kIdeaCount];
};

#endif
