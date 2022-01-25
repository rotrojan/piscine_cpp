/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:06:37 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/25 14:48:57 by rotrojan         ###   ########.fr       */
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

int	Span::longestSpan(void) {
	if (this->_data.size() <= 1)
		throw std::runtime_error("Span to small");
	return (*std::max_element(this->_data.begin(), this->_data.end()) - *std::min_element(this->_data.begin(), this->_data.end()));
}

int	Span::shortestSpan(void) {
	if (this->_data.size() <= 1)
		throw std::runtime_error("Span to small");
	int shortest_span = INT_MAX;
	std::vector<int> tmp = this->_data;
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::const_iterator it = tmp.begin(), next = it + 1; next != tmp.end(); it++, next++) {
		int tmp_span = abs(*it - *next);
		if (tmp_span < shortest_span)
			shortest_span = tmp_span;
	}
	return (shortest_span);
}

std::vector<int>	&Span::getData(void) {
	return (this->_data);
}

void	Span::addInRange(std::vector<int>::iterator it, std::vector<int>::iterator ite) {
	if (this->_data.size() + (ite - it) > this->_maxSize)
		throw std::runtime_error("Cannot fill span");
	for (; it != ite; it++)
		this->_data.push_back(*it);
}

std::ostream	&operator<<(std::ostream &ostream, Span &rhs) {
	for (std::vector<int>::const_iterator it = rhs.getData().begin(); it != rhs.getData().end(); it++) {
		ostream << *it;
		if (it + 1 != rhs.getData().end())
			ostream << " ";
	}
	return (ostream);
}
