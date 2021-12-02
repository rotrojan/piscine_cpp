/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:21:37 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/02 23:20:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Say Hello to " << this->_name << " as he joins the game !" << std::endl;
}

ScavTrap::ScavTrap(std::string name, ScavTrap &scavtrap)
{
	std::cout << "Say Hello to " << this->_name << ", the copy of "
		<< scavtrap.getName() << " as he joins the game !" << std::endl;
	*this = scavtrap;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_name << " had enough of the game." << std::endl;
}

// ScavTrap	&ScavTrap::operator=(ScavTrap &scavtrap)
// {
	// this->_hitPoints = scavtrap.getHitPoints();
	// this->_energyPoints = scavtrap.getEnergyPoints();
	// this->_attackDamage = scavtrap.getAttackDamage();
	// return (*this);
// }
