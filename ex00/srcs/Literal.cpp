/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:33:24 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/18 23:04:13 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Literal.class.hpp"

void	Literal::_set_flags(void) {

	double d = this->_double;

	if (d < INT_MIN || d > INT_MAX || static_cast<double>(this->_int) != d)
		this->_flags |= IMPOSSIBLEINT | IMPOSSIBLECHAR;
	else if (d < 0 || d > 127)
		this->_flags |= IMPOSSIBLECHAR;
	else if (d < ' ' || d > '~')
		this->_flags |= NONDISPLAYABLECHAR;
}

bool	Literal::_is_int(char const *arg) {

	char *end_ptr = NULL;
	long int res = strtol(arg, &end_ptr, 10);

	if (*end_ptr != '\0' || errno != 0 || res > INT_MAX || res < INT_MIN)
		return (false);

	this->_type = INT;
	this->_int = static_cast<int>(res);
	return (true);
}

bool	Literal::_is_double(char const *arg) {

	char *end_ptr = NULL;
	double res = strtod(arg, &end_ptr);

	if (*end_ptr != '\0' || errno != 0 || res == HUGE_VAL)
		return (false);
	this->_type = DOUBLE;
	this->_double = res;
	return (true);
}

bool	Literal::_is_float(char const *arg) {

	char *end_ptr = NULL;
	float res = strtof(arg, &end_ptr);

	if (*end_ptr != 'f' || *(end_ptr + 1) != '\0' || end_ptr - arg <= 0
		|| res == HUGE_VALF || errno != 0)
		return (false);
	this->_type = FLOAT;
	this->_float = res;
	return (true);
}

bool	Literal::_is_char(char const *arg) {
	char c = arg[0];

	if (arg[1] != '\0' || c < ' ' || c > '~') // range of printable ascii characters for c
		return (false);
	this->_char = c;
	this->_type = CHAR;
	return (true);
}

Literal::Literal(char const *arg): _flags(0) {
	if (this->_is_int(arg) == false
		&& this->_is_double(arg) == false
		&& this->_is_float(arg) == false
		&& this->_is_char(arg) == false)
		this->_type = TYPE_ERROR;

	enum e_type type = this->_type;
	char c = this->_char;
	int n = this->_int;
	float f = this->_float;
	double d = this->_double;
	switch (type) {
		case CHAR:
			this->_int = static_cast<int>(c);
			this->_float = static_cast<float>(c);
			this->_double = static_cast<double>(c);
			break ;
		case INT:
			this->_char = static_cast<char>(n);
			this->_float = static_cast<float>(n);
			this->_double = static_cast<double>(n);
			break ;
		case FLOAT:
			this->_char = static_cast<char>(f);
			this->_int = static_cast<int>(f);
			this->_double = static_cast<double>(f);
			break ;
		case DOUBLE:
			this->_char = static_cast<char>(d);
			this->_int = static_cast<int>(d);
			this->_float = static_cast<float>(d);
			break ;
		default:
			this->_flags |=
				IMPOSSIBLEDOUBLE | IMPOSSIBLEFLOAT | IMPOSSIBLEINT | IMPOSSIBLECHAR;
			break ;
	}
	this->_set_flags();
}

Literal::Literal(Literal const &literal) {

	*this = literal;
}

Literal	&Literal::operator=(Literal const &rhs) {

	if (this != &rhs) {
		this->_type = rhs._type;
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return (*this);
}

void	Literal::print(void) {

	char flags = this->_flags;

	std::cout << "char: ";
	if (flags & IMPOSSIBLECHAR)
		std::cout << "impossible";
	else if (flags & NONDISPLAYABLECHAR)
		std::cout << "Non displayable";
	else
		std::cout << "'" << this->_char << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (flags & IMPOSSIBLEINT)
		std::cout << "impossible";
	else
		std::cout << this->_int;
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: ";
	if (flags & IMPOSSIBLEFLOAT)
		std::cout << "impossible";
	else
		std::cout << this->_float << "f";
	std::cout << std::endl;

	std::cout << "double: ";
		if (flags & IMPOSSIBLEDOUBLE)
			std::cout << "impossible";
		else
			std::cout << this->_float;
		std::cout << std::endl;
}
