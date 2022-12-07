/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 00:25:49 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.class.hpp"

Cat::Cat(void): Animal("cat")
{
	std::cout << "This animal is a cat." << std::endl;
}

Cat::Cat(Cat const &cat): Animal(cat)
{
	*this = cat;
	std::cout << "A copy of a cat of type " << this->_type
		<< " has been created." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "A cat has been destroyed." << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat assignation operator called." << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void	Cat::make_sound(void) const
{
	std::cout << "Meeeeeooooow!" << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, Cat const &rhs)
{
	ostream << rhs.get_type();
	return (ostream);
}
