/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:15:53 by bigo              #+#    #+#             */
/*   Updated: 2022/01/16 13:20:51 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_CLASS_HPP
# define LITERAL_CLASS_HPP
# include <string>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class Literal {
	public:
		Literal(std::string const &str_literal = "0");
		Literal(Literal const &literal);
		virtual ~Literal(void);
		Literal		&operator=(Literal const &rhs);
		operator	char(void);
		// operator	double(void);
		
	private:
		enum e_type	_type;
		std::string	_str_literal;
};

#endif
