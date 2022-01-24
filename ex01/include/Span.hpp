/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:59:18 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/24 23:01:04 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <ostream>

class Span {
	public:
		Span(int N = 0);
		Span(Span const &span);
		Span	&operator=(Span const &rhs);
		virtual ~Span(void);
		void				addNumber(int nb);
		int					longestSpan(void);
		int					shortestSpan(void);
		std::vector<int> &getData(void);
		void	addInRange(std::vector<int>::iterator it, std::vector<int>::iterator ite);
	private:
		std::vector<int>				_data;
		const unsigned long int			_maxSize;
};

std::ostream	&operator<<(std::ostream &ostream, Span &rhs);

#endif
