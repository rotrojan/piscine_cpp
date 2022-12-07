/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:06:37 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/27 23:14:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <algorithm>
#include <climits>
#include "Span.hpp"

Span::Span(int N): _maxSize(N) {
	this->_data.reserve(N);
}

Span::Span(Span const &span): _maxSize(span._maxSize) {
	this->_data.reserve(span._maxSize);
	*this = span;
}

Span	&Span::operator=(Span const &rhs) {
	if (this->_data.size() == this->_maxSize)
		throw std::runtime_error("Cannot assign span");
	if (this != &rhs) {
		this->_data = rhs._data;
	}
	return (*this);
}

Span::~Span(void) {
}

void	Span::addNumber(int nb) {
	if (this->_data.size() == this->_maxSize)
		throw std::runtime_error("Span full");
	this->_data.push_back(nb);
}

unsigned int	Span::longestSpan(void) {
	if (this->_data.size() <= 1)
		throw std::runtime_error("Span to small");
	return (*std::max_element(this->_data.begin(), this->_data.end()) - *std::min_element(this->_data.begin(), this->_data.end()));
}

unsigned int	Span::shortestSpan(void) {
	if (this->_data.size() <= 1)
		throw std::runtime_error("Span to small");
	unsigned int shortest_span = UINT_MAX;
	std::vector<int> tmp = this->_data;
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::const_iterator it = tmp.begin(), next = it + 1; next != tmp.end(); it++, next++) {
		unsigned int tmp_span = *next - *it;
		if (tmp_span < shortest_span)
			shortest_span = tmp_span;
	}
	return (shortest_span);
}

std::vector<int>	&Span::getData(void) {
	return (this->_data);
}

std::ostream	&operator<<(std::ostream &ostream, Span &rhs) {
	for (std::vector<int>::const_iterator it = rhs.getData().begin(); it != rhs.getData().end(); it++) {
		ostream << *it;
		if (it + 1 != rhs.getData().end())
			ostream << " ";
	}
	return (ostream);
}
