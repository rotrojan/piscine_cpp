/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:21:37 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/06 17:09:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << this->_name << " is a FragTrap." << std::endl;
}

FragTrap::FragTrap(FragTrap const &fragtrap): ClapTrap(fragtrap)
{
	std::cout << this->_name << " is a FragTrap." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Enough for "<< this->_name << " the FragTrap." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &fragtrap)
{
	if (this != &fragtrap)
		*this = fragtrap;
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << this->_name << " attacks fearlessly " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " is requesting the highest of all fives !" << std::endl;
}
