/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:44:18 by bigo              #+#    #+#             */
/*   Updated: 2021/12/13 23:32:39 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"

AMateria::AMateria(AMateria const &materia)
{
	*this = materia;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const	&AMateria::get_type(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* " << this->_type << " is used on " << target.get_name()
		<< " *" << std::endl;
}
