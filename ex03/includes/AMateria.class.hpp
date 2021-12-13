/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:44:18 by bigo              #+#    #+#             */
/*   Updated: 2021/12/13 16:05:48 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP
# include <string>
# include "ICharacter.class.hpp"

class	AMateria
{
	public:
		AMateria(void) {};
		AMateria(std::string const &type): _type(type) {};
		AMateria(AMateria const &materia);
		virtual ~AMateria(void) {};
		AMateria			&operator=(AMateria const &rhs);
		std::string const	&get_type(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
	protected:
		std::string	_type;
};

#endif
