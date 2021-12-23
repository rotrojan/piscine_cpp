/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:50:53 by bigo              #+#    #+#             */
/*   Updated: 2021/12/23 11:46:47 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP
# include <iostream>
# include <string>
# include "ICharacter.class.hpp"
# include "AMateria.class.hpp"
# define SIZE_INVENTORY 4

class	Character: public ICharacter
{
	public:
		Character(std::string name = "Cloud");
		Character(Character const &character);
		~Character();
		Character			&operator=(Character const &rhs);
		std::string const	&get_name() const;
		void				equip(AMateria *materia);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
	private:
		std::string	_name;
		AMateria	*_inventory[SIZE_INVENTORY];
};

#endif
