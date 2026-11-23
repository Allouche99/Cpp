#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
    public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    virtual void makeSound() const;
    void setIdea(int i, const std::string &idea);
	const std::string &getIdea(int i) const;
    private : 
       Brain *_brain;
};
#endif