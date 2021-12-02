/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:40:12 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/02 21:28:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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
