#ifndef Ice_HPP
#define Ice_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice : public AMateria
{
    public:
    Ice();
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    virtual ~Ice();

    AMateria* clone() const;
    virtual void use(ICharacter& target);

    private:

};
#endif