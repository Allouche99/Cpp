
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test du sujet ===" << std::endl;
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j;
		delete i;
	}

	std::cout << "\n=== Tableau d'animaux ===" << std::endl;
	{
		const int size = 10;
		Animal *animals[size];

		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();

		for (int i = 0; i < size; i++)
			animals[i]->makeSound();

		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	std::cout << "\n=== Deep copy : constructeur par recopie ===" << std::endl;
	{
        Dog a;
        a.setIdea(0, "bone");
        Dog b;
		b = a;
        a.setIdea(0, "ball");
        std::cout << "a: " << a.getIdea(0) << std::endl;   // ball
        std::cout << "b: " << b.getIdea(0) << std::endl;   // bone
	}
    
    std::cout << "\n=== Deep copy : operator= ===" << std::endl;
	{
		Cat c;
		c.setIdea(0, "mouse");

        Cat d = c;
		c.setIdea(0,"fish");

		std::cout << "c: " << c.getIdea(0)<< std::endl;   // fish
		std::cout << "d: " << d.getIdea(0) << std::endl;   // mouse
	}
	return 0;
}
