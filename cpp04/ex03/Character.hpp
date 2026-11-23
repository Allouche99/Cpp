#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;
class ICharacter;
class Character : public ICharacter 
{
    public:
    Character(std::string const &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();
    
    virtual std::string const &getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    
    private:
    std::string _name;
    AMateria* _inventory[4];
};
#endif
