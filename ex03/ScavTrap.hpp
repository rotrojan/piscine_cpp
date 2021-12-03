/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:15:17 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/03 21:49:08 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(std::string name = "Scavtrap");
		ScavTrap(std::string name, ScavTrap &scavtrap);
		~ScavTrap(void);
		ScavTrap					&operator=(ScavTrap &scavtrap);
		void						attack(std::string const &target);
		void						guardGate(void);
	protected:
		static unsigned int const	_defaultHitPoints = 100;
		static unsigned int const	_defaultEnergyPoints = 50;
		static unsigned int const	_defaultAttackDamage = 20;
};

#endif
