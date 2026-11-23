#include "Cat.hpp"
#include "iostream"
#include "AAnimal.hpp"


Cat::Cat() : AAnimal()
{
	type = "cat";
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	type = "cat";
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout <<"Cat copy assignment operator called"<< std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "CatSound~~~~"<< std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destroyed" << std::endl;
}