#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("ana");
	d.whoAmI();
	d.attack("yas");
	d.guardGate();
	d.highFivesGuys();

	DiamondTrap copy(d);
	DiamondTrap other;
	other = d;
	other.whoAmI();
	return 0;
}