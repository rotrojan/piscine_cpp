/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:01:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/03 17:18:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

void	display_claptrap(ClapTrap &claptrap)
{
	std::cout << claptrap.getName() << " has " << claptrap.getHitPoints()
		<< " hit points, " << claptrap.getEnergyPoints()
		<< " energy points and makes " << claptrap.getAttackDamage() 
		<< " points of damage at each attack." << std::endl;
}

int main(void)
{
	ClapTrap	bob("Bob");
	ClapTrap	tod("Tod", bob);
	display_claptrap(bob);
	display_claptrap(tod);
	bob.attack("a skag");
	tod.takeDamage(12);
	tod.beRepaired(10);
	std::cout << std::endl;

	ScavTrap	tag("Tag");
	ScavTrap	paf("Paf", tag);
	display_claptrap(tag);
	display_claptrap(paf);
	tag.attack("an Arch Guardian");
	paf.guardGate();
	return (EXIT_SUCCESS);
}
