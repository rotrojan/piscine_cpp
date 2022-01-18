/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:05:06 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/18 23:02:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_CLASS_HPP
# define LITERAL_CLASS_HPP
# define NONDISPLAYABLECHAR 1<<0
# define IMPOSSIBLECHAR 1<<1
# define IMPOSSIBLEINT 1<<2
# define IMPOSSIBLEFLOAT 1<<3
# define IMPOSSIBLEDOUBLE 1<<4

enum e_type {
	TYPE_ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	TYPE_MAX
};

class Literal {
	public:
		Literal(char const *arg = "0");
		Literal(Literal const &literal);
		~Literal(void) {};
		Literal &operator=(Literal const &rhs);
		void	print(void);
	private:
		char			_char;
		int				_int;
		float			_float;
		double			_double;
		enum e_type		_type;
		unsigned char	_flags;
		bool			_is_int(char const *arg);
		bool			_is_double(char const *arg);
		bool			_is_float(char const *arg);
		bool			_is_char(char const *arg);
		void			_set_flags(void);
};

#endif
