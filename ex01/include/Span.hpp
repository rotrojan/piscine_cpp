/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:59:18 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/27 23:14:28 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <map>
# include <ostream>

class Span {
	public:
		Span(int N = 0);
		Span(Span const &span);
		Span	&operator=(Span const &rhs);
		~Span(void);
		void					addNumber(int nb);
		template <typename Iterator>
		void	addNumber(Iterator it, Iterator ite) {
			if (this->_data.size() + std::distance(it, ite) > this->_maxSize)
				throw std::runtime_error("Cannot fill span");
			for (; it != ite; it++)
				this->_data.push_back(*it);
		}
		unsigned int			longestSpan(void);
		unsigned int			shortestSpan(void);
		std::vector<int>		&getData(void);
	private:
		std::vector<int>		_data;
		const unsigned long int	_maxSize;
};

std::ostream	&operator<<(std::ostream &ostream, Span &rhs);

#endif
