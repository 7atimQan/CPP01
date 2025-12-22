#include "Zombie.hpp"

void Zombie::announce(void) const
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

std::string Zombie::getName() const
{
	return (name);
}

Zombie::~Zombie(){
	std::cout << name << " is no longer here !" << std::endl;
}