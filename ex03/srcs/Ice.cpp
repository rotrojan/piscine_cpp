/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:44:18 by bigo              #+#    #+#             */
/*   Updated: 2021/12/23 08:32:51 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.class.hpp"

Ice::Ice(Ice const &ice): AMateria("ice")
{
	*this = ice;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	(void)rhs;
	return (*this);
}

Ice	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.get_name()
		<< " *" << std::endl;
}
