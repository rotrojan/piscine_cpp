/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:44:18 by bigo              #+#    #+#             */
/*   Updated: 2021/12/13 23:32:51 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP
# include <string>
# include "AMateria.class.hpp"

class	Cure: public AMateria
{
	public:
		Cure(void): AMateria("cure") {};
		Cure(Cure const &cure);
		~Cure(void) {};
		Cure		&operator=(Cure const &rhs);
		Cure		*clone(void) const;
		void	use(ICharacter &target);
};

#endif
