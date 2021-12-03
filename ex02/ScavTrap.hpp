/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:15:17 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/03 21:18:07 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string name = "Scavtrap");
		ScavTrap(std::string name, ScavTrap &scavtrap);
		~ScavTrap(void);
		ScavTrap	&operator=(ScavTrap &scavtrap);
		void		attack(std::string const &target);
		void		guardGate(void);
};

#endif
