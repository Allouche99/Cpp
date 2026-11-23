#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    delete i;
    delete j;

    return 0;

}