/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:44:18 by bigo              #+#    #+#             */
/*   Updated: 2021/12/13 22:51:36 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP
# include <string>
# include "AMateria.class.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void): AMateria("ice") {};
		Ice(Ice const &ice);
		~Ice(void) {};
		Ice		&operator=(Ice const &rhs);
		Ice		*clone(void) const;
		void	use(ICharacter &target);
};

#endif
