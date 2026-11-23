#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    src->learnMateria(ice);
    src->learnMateria(cure);
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    // return 0;
    // more test
    IMateriaSource* srcUsless = new MateriaSource();
    srcUsless->learnMateria(ice);
    AMateria* unknown = srcUsless->createMateria("fire");
    if (unknown == NULL)
        std::cout << "Unknown materia" << std::endl;
    delete srcUsless;
    IMateriaSource* src2 = new MateriaSource();

    ICharacter* yas = new Character("yas");
    ICharacter* aya = new Character("aya");

    src2->learnMateria(ice);
    src2->learnMateria(cure);
    src2->learnMateria(ice);
    src2->learnMateria(cure);
    
    AMateria *uneEquip;
    uneEquip = src2->createMateria("cure");

    yas->equip(src2->createMateria("ice"));
    yas->equip(uneEquip);
    yas->equip(src2->createMateria("ice"));
    yas->equip(src2->createMateria("cure"));
    for(int i = 0; i < 4; i++)
        yas->use(i, *aya);

    AMateria *full;
    full = src2->createMateria("cure");
    yas->equip(full); // full
    
    yas->unequip(1);
    for(int i = 0; i < 4; i++)
        yas->use(i, *aya);
    Character copy(*static_cast<Character*>(yas));
    copy.use(0, *aya);
    delete uneEquip;
    delete full;
    delete yas;
    delete src2;
    delete aya;
    delete ice;
    delete cure;
    return 0;
}