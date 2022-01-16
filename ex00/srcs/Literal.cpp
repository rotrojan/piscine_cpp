/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:15:53 by bigo              #+#    #+#             */
/*   Updated: 2022/01/16 13:20:47 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Literal.class.hpp"

static enum e_type	get_type(

Literal::Literal(std::string const &str_literal): _str_literal(str_literal) {
}

Literal::Literal(Literal const &literal) {
	*this = literal;
}

Literal::~Literal(void) {
}

Literal	&Literal::operator=(Literal const &rhs) {
	if (this != &rhs)
		this->_str_literal = rhs._str_literal;
	return (*this);
}

double Literal::to_double(void) {
}
