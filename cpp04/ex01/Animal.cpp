#include "Animal.hpp"
#include "iostream"

Animal::Animal() : type("Animal")
{
    std::cout<<"Animal default constrocted" << std::endl;
}

Animal::Animal(std::string type) : type("type")
{
    std::cout<<"Animal " << type << "constroctored" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal copy constructed" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout <<"Animal copy assignment operator called"<< std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

void Animal::makeSound() const
{
	std::cout << "* some animal sound *" << std::endl;
}

const std::string &Animal::getType() const
{
	return (type);
}

Animal::~Animal()
{
    std::cout<<"Animal destroyed" << std::endl;
}