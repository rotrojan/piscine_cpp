/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 00:21:24 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP
# include <iostream>
# include "Animal.class.hpp"
# include "Brain.class.hpp"

class	Dog: public Animal
{
	public:
		Dog(void);
		Dog(Dog const &dog);
		~Dog(void);
		Dog &operator=(Dog const &rhs);
		void				make_sound(void) const;
		Brain const			&get_brain(void);
	private:
		Brain				*_brain;
};

std::ostream	&operator<<(std::ostream &ostream, Dog const &rhs);

#endif
