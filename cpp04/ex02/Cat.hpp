#ifndef Cat_HPP
#define Cat_HPP

#include "AAnimal.hpp"
#include <string>

class Cat : public AAnimal
{
    public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    virtual void makeSound() const;

};
#endif