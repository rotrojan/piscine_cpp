/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/07 23:44:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP
# include <iostream>
# include "WrongAnimal.class.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &wrongcat);
		~WrongCat(void);
		WrongCat &operator=(WrongCat const &rhs);
		std::string const	&get_type(void) const;
		void				make_sound(void) const;
	protected:
		std::string	_type;
};

std::ostream	&operator<<(std::ostream &ostream, WrongCat const &rhs);

#endif
