/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:15:17 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/06 17:38:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(std::string name = "Fragtrap");
		FragTrap(FragTrap const &fragtrap);
		~FragTrap(void);
		FragTrap	&operator=(FragTrap const &fragtrap);
		void		attack(std::string const &target);
		void		highFivesGuys(void);
	protected:
		static unsigned int const	_defaultHitPoints = 100;
		static unsigned int const	_defaultEnergyPoints = 100;
		static unsigned int const	_defaultAttackDamage = 30;
};

#endif
