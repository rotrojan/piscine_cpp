/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:59:18 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/25 17:35:52 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <ostream>
# include <iterator>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		//typedef
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		//canonical form
		MutantStack(void) {
		};
		MutantStack(MutantStack const &mutantstack) {
			*this = mutantstack;
		};
		MutantStack	&operator=(MutantStack const &rhs) {
			if (this != rhs)
				this->_stack = rhs._stack;
			return (*this);
		};
		~MutantStack(void) {
		};
		// iterators
		iterator	begin(void) {
			return (this->c.begin());
		};
		iterator	end(void) {
			return (this->c.end());
		};
		// const iterators
		const_iterator	begin(void) const {
			return (this->c.begin());
		};
		const_iterator	end(void) const {
			return (this->c.end());
		};
		// reverse iterators
		reverse_iterator	rbegin(void) {
			return (this->c.rbegin());
		};
		reverse_iterator	rend(void) {
			return (this->c.rend());
		};
		// const reverse iterators
		const_reverse_iterator	rbegin(void) const {
			return (this->c.rbegin());
		};
		const_reverse_iterator	rend(void) const {
			return (this->c.rend());
		};
};

#endif
