#include "Cat.hpp"
#include "iostream"
#include "Animal.hpp"


Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout <<"Cat copy assignment operator called"<< std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
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