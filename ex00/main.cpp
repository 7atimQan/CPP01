#include "Zombie.hpp"

int main()
{
	Zombie		*z;
	std::string	zombieName;
	std::string chumpName;

	std::cout << "Enter zombie name :" << std::endl;
	std::cin >> zombieName;

	std::cout << "Enter chump name :" << std::endl;
	std::cin >> chumpName;

	z = newZombie(zombieName);
	z->announce();
	delete z;
	
	randomChump(chumpName);
}