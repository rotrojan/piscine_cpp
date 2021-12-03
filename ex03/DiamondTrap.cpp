/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:21:37 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/03 22:01:24 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::_defaultHitPoints;
	this->_energyPoints = ScavTrap::_defaultEnergyPoints;
	this->_attackDamage = FragTrap::_defaultAttackDamage;
	std::cout << this->_name << " is a DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name, DiamondTrap &diamondtrap)
	: ClapTrap(name + "_clap_name", diamondtrap), ScavTrap(name, diamondtrap), FragTrap(name, diamondtrap)
{
	std::cout << this->_name << " is a DiamondTrap." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Enough for "<< this->_name << " the DiamondTrap." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &diamondtrap)
{
	if (&diamondtrap != this)
		*this = diamondtrap;
	return (*this);
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "The ClapTrap name of " << this->_name << " is " << this->getName() << std::endl;
}
