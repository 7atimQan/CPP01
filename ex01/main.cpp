#include "Zombie.hpp"

int	main()
{
	int			N;
	std::string name;

	std::cout << "Enter the number of zombies :" << std::endl;
	std::cin >> N;
	if (N < 0)
		return 1;

	std::cout << "Enter the name of each zombie :" << std::endl;
	std::cin >> name;

	Zombie *horde = zombieHorde(N, name);
	if (horde == NULL)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;

	return (0);
}
