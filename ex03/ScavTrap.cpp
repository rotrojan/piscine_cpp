/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:21:37 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/03 18:21:24 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << this->_name << " is a SC4V-TP." << std::endl;
}

ScavTrap::ScavTrap(std::string name, ScavTrap &scavtrap): ClapTrap(name, scavtrap)
{
	std::cout << this->_name << " is a SC4V-TP." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Enough for "<< this->_name << " the SC4V-TP." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap &scavtrap)
{
	if (&scavtrap != this)
		*this = scavtrap;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << this->_name << " attacks wildly " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is now guarding the Gate." << std::endl;
}
