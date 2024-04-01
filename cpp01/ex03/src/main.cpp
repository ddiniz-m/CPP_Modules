
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"
#include "../inc/Weapon.hpp"

int main()
{
	{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("wooden club");
		bob.attack();
		club.setType("iron club");
		bob.attack();
		Weapon sword("katana");
		bob.setWeapon(sword);
		bob.attack();
	}
	{
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		club.setType("wooden club");
		jim.attack();
		club.setType("iron club");
		jim.attack();
	}
	return 0;
}
