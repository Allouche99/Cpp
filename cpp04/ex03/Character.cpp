#include <iostream>
#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4;i++)
        _inventory[i] = NULL;
    // std::cout << "Character " << _name
    //           << " created." << std::endl;
}

Character::Character(const Character &other)
    : _name(other._name)
{
    for(int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
        if (other._inventory[i] != NULL)
            this->_inventory[i] = other._inventory[i]->clone();
    }
//     std::cout << "Character " << _name
//           << " copied"<< std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for(int i = 0; i < 4; i++)
        {
            delete (this->_inventory[i]);
            this->_inventory[i] = NULL;
            if (other._inventory[i] != NULL)
                this->_inventory[i] = other._inventory[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4;i++)
        delete (_inventory[i]);
    // std::cout << "Character " << _name
    //       << " destroyed." << std::endl;
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character:: equip(AMateria* m)
{
     if (m == NULL)
        return; 
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return;
        }
    }
}

void Character:: unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        this->_inventory[idx] = NULL;
    }
}

void Character:: use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3 && _inventory[idx] != NULL)
    {
        this->_inventory[idx]->use(target);
    }
}