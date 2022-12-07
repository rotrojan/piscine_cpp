/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:38:10 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/22 23:10:56 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name): _name(name), _weapon(NULL) {};
		~HumanB() {};
		void	setWeapon(Weapon &weapon);
		void	attack(void) const;
	private:
		std::string const	_name;
		Weapon				*_weapon;
};

#endif
