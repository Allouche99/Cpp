#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();

		club.setType("some other type of club");
		bob.attack();
	}

	std::cout << "----------" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		jim.setWeapon(&club);
		jim.attack();

		club.setType("some other type of club");
		jim.attack();
	}

	std::cout << "----------" << std::endl;
	//limite : HumanB SANS arme du tout
	{
		HumanB naked("mo salah");

		naked.attack();
	}

	return (0);
}
