#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "[DEBUG] I love having extra bacon !" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG",
							"INFO",
							"WARNING",
							"ERROR"};

	void (Harl::*funcPTR[4])() = {&Harl::debug,
								&Harl::info,
								&Harl::warning,
								&Harl::error};

	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break ;
	}

	switch (i)
	{
		case 0:
			(this->*funcPTR[0])();
			std::cout << std::endl;
		case 1:
			(this->*funcPTR[1])();
			std::cout << std::endl;
		case 2:
			(this->*funcPTR[2])();
			std::cout << std::endl;
		case 3:
		{
			(this->*funcPTR[3])();
			break ;
		}
		default:
			std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}