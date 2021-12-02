/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:40:12 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/02 22:24:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#define UINTMAX 4294967295

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "Greet " << this->_name << " as he joins the game !" << std::endl;
}

ClapTrap::ClapTrap(std::string name, ClapTrap &claptrap): _name(name)
{
	std::cout << "Greet " << this->_name << ", the copy of "
		<< claptrap.getName() << " as he joins the game !" << std::endl;
	*this = claptrap;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->_name << " has leaved the game." << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &claptrap)
{
	this->_hitPoints = claptrap.getHitPoints();
	this->_energyPoints = claptrap.getEnergyPoints();
	this->_attackDamage = claptrap.getAttackDamage();
	return (*this);
}

std::string const	&ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
void	ClapTrap::attack(std::string const &target)
{
	std::cout << this->_name << " attacks fiercely " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_energyPoints)
		this->_energyPoints = 0;
	else
		this->_energyPoints -= amount;
	std::cout << this->_name << " has taken " << amount << " points of damage!" << std::endl;
	std::cout << this->_name << " now have " << this->_energyPoints
		<< " energy points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (amount + this->_energyPoints < this->_energyPoints)
		this->_energyPoints = UINTMAX;
	else
		this->_energyPoints += amount;
	std::cout << this->_name << " has been repaired of " << amount << " energy points." << std::endl;
	std::cout << this->_name << " now have " << this->_energyPoints
		<< " energy points." << std::endl;
}
