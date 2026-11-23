#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal
{
    public:

    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0;
    const std::string &getType() const;

    protected:
    std::string type;
    AAnimal();
    AAnimal(const std::string type);
};
#endif