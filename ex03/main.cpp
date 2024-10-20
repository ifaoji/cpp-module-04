#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void PrintHeader(const std::string &header) {

  std::cout << "----" << std::endl
            << header << std::endl
            << "----" << std::endl;
}

int main() {
  {
    PrintHeader("MatiaSource correct inventory handling");

    AMateria *materias[5] = {new Ice(), new Ice(), new Cure(), new Ice(),
                             new Cure()};
    IMateriaSource *src = new MateriaSource();
    for (int i = 0; i < 5; i++) {
      src->learnMateria(materias[i]);
    }

    delete src;
    // Materia source cannot hold the last item
    delete materias[4];
  }

  {
    PrintHeader("MatiaSource learn same materia");

    AMateria *ice = new Ice();
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(ice);
    src->learnMateria(ice);
    src->learnMateria(ice);
    src->learnMateria(ice);

    delete src;
  }

  {
    PrintHeader("MatiaSource deep copy");

    AMateria *materias[4] = {
        new Ice(),
        new Ice(),
        new Cure(),
        new Ice(),
    };
    IMateriaSource *src = new MateriaSource();
    for (int i = 0; i < 4; i++) {
      src->learnMateria(materias[i]);
    }

    IMateriaSource *src_copy = new MateriaSource(*(MateriaSource *)src);
    MateriaSource src_copy2;
    src_copy2 = *(MateriaSource *)src;

    delete src;
    delete src_copy;
  }

  {
    PrintHeader("MatiaSource learn same materia");

    AMateria *ice = new Ice();
    ICharacter *me = new Character("me");
    me->equip(ice);
    me->equip(ice);
    me->equip(ice);
    me->equip(ice);

    delete me;
  }

  {
    PrintHeader("Character deep copy");

    AMateria *materias[4] = {
        new Ice(),
        new Ice(),
        new Cure(),
        new Ice(),
    };
    ICharacter *me = new Character("me");
    for (int i = 0; i < 4; i++) {
      me->equip(materias[i]);
    }

    ICharacter *me_copy = new Character(*(Character *)me);
    Character me_copy2;
    me_copy2 = *(Character *)me;

    delete me;
    delete me_copy;
  }

  {
    PrintHeader("Character unequip not freed");

    AMateria *materias[4] = {
        new Ice(),
        new Ice(),
        new Cure(),
        new Ice(),
    };
    ICharacter *me = new Character("me");
    for (int i = 0; i < 4; i++) {
      me->equip(materias[i]);
    }

    me->unequip(1);

    delete me;
    delete materias[1];
  }

  {
    PrintHeader("Character unequip");

    AMateria *materias[4] = {
        new Ice(),
        new Ice(),
        new Cure(),
        new Ice(),
    };

    AMateria *other = new Cure();
    ICharacter *me = new Character("me");
    for (int i = 0; i < 4; i++) {
      me->equip(materias[i]);
    }

    me->unequip(1);
    me->equip(other);

    delete me;
    delete materias[1];
  }

  {
    PrintHeader("Character unequip correct ordering");

    AMateria *materias[4] = {
        new Ice(),
        new Ice(),
        new Cure(),
        new Ice(),
    };

    ICharacter *me = new Character("me");
    for (int i = 0; i < 4; i++) {
      me->equip(materias[i]);
    }

    me->unequip(3);
    me->unequip(2);
    me->unequip(1);
    me->unequip(0);

    delete me;
    delete materias[0];
    delete materias[1];
    delete materias[2];
    delete materias[3];
  }

  {
    PrintHeader("Use Invalid Materia");

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    AMateria *tmp = src->createMateria("ice");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    me->unequip(2);
    me->use(2, *bob);

    me->equip(src->createMateria("ice"));
    me->use(2, *bob);

    delete src;
    delete bob;
    delete me;
    delete tmp;
  }

  {
    PrintHeader("Subject");

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
  }
}
