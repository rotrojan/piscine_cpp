/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:44:18 by bigo              #+#    #+#             */
/*   Updated: 2021/12/12 22:48:39 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP
# include <string>
# include "AMateria.class.hpp"

class	Ice: public AMateria
{
	public:
		Ice(std::string const &type = "ice");
		Ice(Ice const &ice);
		virtual ~Ice(void) {};
		Ice					&operator=(Ice const &rhs);
		std::string const	&getType() const;
		Ice					*clone() const;
		void				use(ICharacter &target);
};

#endif
