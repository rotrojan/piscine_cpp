/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:26:17 by bigo              #+#    #+#             */
/*   Updated: 2021/11/24 17:40:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class	Weapon
{
	public:
		Weapon(std::string type): _type(type) {};
		~Weapon() {};
		std::string const	&getType(void) const;
		void		setType(std::string type);
	private:
		std::string	_type;
};

#endif
