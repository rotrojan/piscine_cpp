/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/07 23:19:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.class.hpp"

WrongCat::WrongCat(void): _type("wrong cat")
{
	std::cout << "This animal is a wrong cat." << std::endl;
}

WrongCat::WrongCat(WrongCat const &wrongcat)
{
	*this = wrongcat;
	std::cout << "A copy of a wrong cat of type " << this->_type
		<< " has been created." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "A wrong cat has been destroyed." << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat assignation operator called." << std::endl;
	this->_type = rhs.get_type();
	return (*this);
}

std::string const	&WrongCat::get_type(void) const
{
	return (this->_type);
}

void	WrongCat::make_sound(void) const
{
	std::cout << "Fake Meeeeeooooow!" << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, WrongCat const &rhs)
{
	ostream << rhs.get_type();
	return (ostream);
}
