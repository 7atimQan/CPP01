#include "Harl.hpp"

int main()
{
	Harl 		h;
	std::string	level;

	std::cout << "Choose your level : DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cin >> level;

	h.complain(level);
}