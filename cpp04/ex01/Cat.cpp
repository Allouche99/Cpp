#include "Cat.hpp"
#include "Brain.hpp"
#include "iostream"
#include "Animal.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "CatSound~~~~"<< std::endl;
}
void Cat::setIdea(int i, const std::string &idea)
{
	if (i < 0 || i >= 100)
		return;
	_brain->ideas[i] = idea;
}

const std::string &Cat::getIdea(int i) const
{
	static const std::string empty = "";
	if (i < 0 || i >= 100)
		return empty;
	return _brain->ideas[i];
}