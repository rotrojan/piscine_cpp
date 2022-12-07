/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:21:37 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/06 18:34:07 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	this->_hitPoints = FragTrap::_defaultHitPoints;
	this->_energyPoints = ScavTrap::_defaultEnergyPoints;
	this->_attackDamage = FragTrap::_defaultAttackDamage;
	std::cout << this->ClapTrap::_name << " is a DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamondtrap)
: ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap), _name(diamondtrap.DiamondTrap::getName())
{
	std::cout << this->ClapTrap::_name << " is a DiamondTrap." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Enough for "<< this->ClapTrap::_name << " the DiamondTrap." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &diamondtrap)
{
	if (this != &diamondtrap)
		*this = diamondtrap;
	return (*this);
}

std::string const	&DiamondTrap::getName(void) const
{
	return (this->DiamondTrap::_name);
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "The ClapTrap name of " << this->_name << " is " << this->ClapTrap::getName() << std::endl;
}
