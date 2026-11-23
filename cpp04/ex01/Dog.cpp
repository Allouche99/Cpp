#include "Dog.hpp"
#include "Brain.hpp"
#include "iostream"
#include "Animal.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog default constructed" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::setIdea(int i, const std::string &idea)
{
	if (i < 0 || i >= 100)
		return;
	_brain->ideas[i] = idea;
}

const std::string &Dog::getIdea(int i) const
{
	static const std::string empty = "";
	if (i < 0 || i >= 100)
		return empty;
	return _brain->ideas[i];
}

void Dog::makeSound() const
{
    std::cout << "DogSound~~~~"<< std::endl;
}
