/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:44:18 by bigo              #+#    #+#             */
/*   Updated: 2021/12/12 22:52:50 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"

AMateria::AMateria(AMateria const &materia)
{
	*this = materia;
}

std::string const	&AMateria::get_type(void) const
{
	return (this->_type);
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
