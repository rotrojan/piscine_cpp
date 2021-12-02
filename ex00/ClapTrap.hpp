/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:20:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/02 21:55:42 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>

class	ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(std::string name, ClapTrap &claptrap);
		~ClapTrap(void);
		ClapTrap			&operator=(ClapTrap &claptrap);
		std::string const	&getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergyPoints(void) const;
		unsigned int		getAttackDamage(void) const;
		void				attack(std::string const &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
	private:
		std::string const	_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
};	

#endif
