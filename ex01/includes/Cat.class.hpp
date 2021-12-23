/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/24 00:59:17 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP
# include <iostream>
# include "Animal.class.hpp"
# include "Brain.class.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);
		Cat(Cat const &cat);
		virtual ~Cat(void);
		Cat			&operator=(Cat const &rhs);
		Brain const	*get_brain(void) const;
		void		make_sound(void) const;
	private:
		Brain		*_brain;
};

std::ostream		&operator<<(std::ostream &ostream, Cat const &rhs);

#endif
