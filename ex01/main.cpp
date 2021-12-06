/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:01:25 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/06 16:39:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	ClapTrap	bob;
	std::cout << bob << std::endl;
	std::cout << std::endl;

	ClapTrap	tod(bob);
	std::cout << tod << std::endl;
	std::cout << std::endl;

	bob.attack("a skag");
	tod.takeDamage(5);
	tod.beRepaired(10);
	std::cout << std::endl;

	ScavTrap	tag;
	std::cout << tag << std::endl;
	ScavTrap	paf(tag);
	std::cout << paf << std::endl;
	std::cout << std::endl;

	tag.attack("an Arch Guardian");
	paf.guardGate();
	tag.takeDamage(5);
	tag.beRepaired(10);
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
