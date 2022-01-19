/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:33:24 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/19 17:28:22 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Literal.class.hpp"

void	Literal::_set_flags(void) {

	double d = this->_double;

	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX)
		|| std::isnan(d) == true || std::isinf(d) == true)
		this->_flags |= IMPOSSIBLEINT | IMPOSSIBLECHAR;
	else if (d < CHAR_MIN || d > CHAR_MAX)
		this->_flags |= IMPOSSIBLECHAR;
	else if (std::isprint(this->_char) == false)
		this->_flags |= NONDISPLAYABLECHAR;
}

bool	Literal::_is_int(char const *arg) {

	char *end_ptr = NULL;
	long int res = strtol(arg, &end_ptr, 10);

	if (*end_ptr != '\0' || res > INT_MAX || res < INT_MIN)
		return (false);

	this->_type = INT;
	this->_int = static_cast<int>(res);
	return (true);
}

bool	Literal::_is_double(char const *arg) {

	char *end_ptr = NULL;
	double res = strtod(arg, &end_ptr);

	if (*end_ptr != '\0')
		return (false);

	this->_type = DOUBLE;
	this->_double = res;
	return (true);
}

bool	Literal::_is_float(char const *arg) {

	char *end_ptr = NULL;
	float res = strtof(arg, &end_ptr);

	if (*end_ptr != 'f' || *(end_ptr + 1) != '\0' || end_ptr - arg <= 0)
		return (false);

	this->_type = FLOAT;
	this->_float = res;
	return (true);
}

bool	Literal::_is_char(char const *arg) {

	char c = arg[0];

	if (arg[1] != '\0' || std::isprint(c) == false)
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
	switch (type) {
		case CHAR: {
			char c = this->_char;
			this->_int = static_cast<int>(c);
			this->_float = static_cast<float>(c);
			this->_double = static_cast<double>(c);
			 break ;
		} case INT: {
			int n = this->_int;
			this->_char = static_cast<char>(n);
			this->_float = static_cast<float>(n);
			this->_double = static_cast<double>(n);
			break ;
		} case FLOAT: {
			float f = this->_float;
			this->_char = static_cast<char>(f);
			this->_int = static_cast<int>(f);
			this->_double = static_cast<double>(f);
			break ;
		} case DOUBLE: {
			double d = this->_double;
			this->_char = static_cast<char>(d);
			this->_int = static_cast<int>(d);
			this->_float = static_cast<float>(d);
			break ;
		} default: {
			this->_flags |= IMPOSSIBLEINT | IMPOSSIBLECHAR;
			this->_float = NAN;
			this->_double = NAN;
			break ;
		 }
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

static void	print_char(char const c, unsigned int const flags) {

	std::cout << "char: ";
	if (flags & IMPOSSIBLECHAR)
		std::cout << "impossible";
	else if (flags & NONDISPLAYABLECHAR)
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

static void	print_int(int const n, unsigned int const flags) {

	std::cout << "int: ";
	if (flags & IMPOSSIBLEINT)
		std::cout << "impossible";
	else
		std::cout << n;
	std::cout << std::endl;
}

void	Literal::print(void) {

	std::cout << std::fixed << std::setprecision(1);

	print_char(this->_char, this->_flags);
	print_int(this->_int, this->_flags);

	std::cout << "float: " << this->_float << "f" << std::endl;
	std::cout << "double: " << this->_double << std::endl;
}
