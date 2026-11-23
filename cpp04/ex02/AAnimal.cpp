#include "AAnimal.hpp"
#include "iostream"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout<<"AAnimal Default constrocted" << std::endl;
}

AAnimal::AAnimal(std::string type) : type("type")
{
    std::cout<<"AAnimal " << type << "constroctored" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
    std::cout << "AAnimal copy constructed" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout <<"AAnimal copy assignment operator called"<< std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

const std::string &AAnimal::getType() const
{
	return (type);
}

AAnimal::~AAnimal()
{
    std::cout<<"AAnimal destroyed" << std::endl;
}