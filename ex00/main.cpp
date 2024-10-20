#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void PrintHeader(const std::string &header) {

  std::cout << "----" << std::endl
            << header << std::endl
            << "----" << std::endl;
}

int main() {
  {
    PrintHeader("Animal Canonical Stuff");

    Animal hubert;
    Animal bernhart(hubert);

    hubert = bernhart;
  }

  {
    PrintHeader("Cat");

    Cat cat;

    cat.makeSound();
  }

  {
    PrintHeader("Dog");

    Dog dog;

    dog.makeSound();
  }

  {
    PrintHeader("WrongCat");

    WrongCat cat;

    cat.makeSound();
  }

  {
    PrintHeader("Subject");

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;
  }

  {
    PrintHeader("Wrong Cat");

    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will not output the cat sound!
    meta->makeSound();

    delete meta;
    delete i;
  }
}
