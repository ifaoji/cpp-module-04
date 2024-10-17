#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void PrintHeader(const std::string &header) {

  std::cout << "----" << std::endl
            << header << std::endl
            << "----" << std::endl;
}

int main() {
  {
    PrintHeader("Cat Canonical Stuff");

    Cat hubert;
    Cat bernhart(hubert);

    hubert = bernhart;
  }

  {
    PrintHeader("Dog Canonical Stuff");

    Dog hubert;
    Dog bernhart(hubert);

    hubert = bernhart;
  }

  {
    PrintHeader("Brain Canonical Stuff");

    Brain hubert;
    Brain bernhart(hubert);

    hubert = bernhart;
  }

  {
    PrintHeader("Ideas Ptr Different");

    Brain a;
    Brain b(a);

    a.printIdeasPtr();
    b.printIdeasPtr();
  }

  {
    PrintHeader("Cat Brain Copy");

    Cat a;
    a.printBrainPtr();

    {
      Cat b(a);
      b.printBrainPtr();
    }
  }

  {
    PrintHeader("Dog Brain Copy");

    Dog a;
    a.printBrainPtr();

    {
      Dog b(a);
      b.printBrainPtr();
    }
  }

  {
    PrintHeader("Huge Test");

    Animal *many[10];

    for (int i = 0; i < 5; i++) {
      many[i] = new Cat();
    }

    for (int i = 5; i < 10; i++) {
      many[i] = new Dog();
    }

    for (int i = 0; i < 10; i++) {
      delete many[i];
    }
  }

  {
    PrintHeader("Subject");
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j; // should not create a leak
    delete i;
  }

  // {
  //   PrintHeader("Cannot Instanciate Animal Directly");

  //   Animal a;
  //   a.makeSound();
  // }
}
