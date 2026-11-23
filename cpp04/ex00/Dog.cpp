#include "Dog.hpp"
#include "iostream"
#include "Animal.hpp"


Dog::Dog() : Animal()
{
    type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    type = "Dog";
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout <<"Dog copy assignment operator called"<< std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}
void Dog::makeSound() const
{
    std::cout << "DogSound~~~~"<< std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destroyed" << std::endl;
}