/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/25 14:47:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Span.hpp"

static int	random_nb() {
// This clang attribute allows to not use the seed variable without generating a
// compilation error. The evaluation of the expression (srand(time(NULL)), 0) is
// assigned to this variable.
	static int seed __attribute__((unused)) = (srand(time(NULL)), 0);
	return (rand() % 10000);
}

int main(void) {
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
		Span copy(sp);
		std::cout << copy << std::endl;
	}
	std::cout << std::endl << "==============================================" << std::endl << std::endl;
	{
		std::vector<int> vec(10000000);
		std::generate(vec.begin(), vec.end(), &random_nb);

		Span sp(5);
		try {
			std::cout << "Adding 6 numbers to Span of size 5" << std::endl;
			sp.addInRange(vec.begin(), vec.begin() + 6);
			std::cout << "Range succesfully added" << std::endl;
			std::cout << sp << std::endl; 
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Adding 5 numbers to Span of size 5" << std::endl;
			sp.addInRange(vec.begin(), vec.begin() + 5);
			std::cout << "Range succesfully added" << std::endl;
			std::cout << sp << std::endl; 
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;

		Span empty;
		Span little(1);
		try {
			std::cout << "Adding 1 number to Span of size 0" << std::endl;
			empty.addNumber(42);
			std::cout << "Number succesfully added" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			std::cout << "Adding 1 number to Span of size 1" << std::endl;
			little.addNumber(42);
			std::cout << "Number succesfully added" << std::endl;
			std::cout << "Adding 1 more number to Span of size 1" << std::endl;
			little.addNumber(-42);
			std::cout << "Number succesfully added" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;

		try {
			std::cout << "longestSpan of Span of size 0" << std::endl;
			std::cout << empty.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::cout << "shortestSpan of Span of size 0" << std::endl;
			std::cout << empty.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::cout << "longestSpan of Span of size 1" << std::endl;
			std::cout << little.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::cout << "shortestSpan of Span of size 1" << std::endl;
			std::cout << little.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::cout << "longestSpan of Span of size 5" << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << "shortestSpan of Span of size 5" << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;

		Span big(10000);
		Span very_big(10000000);

		try {
			std::cout << "Adding 10,000,000 numbers in Span of size 10,000,000" << std::endl;
			very_big.addInRange(vec.begin(), vec.end());
			std::cout << "Range succesfully added" << std::endl;
			std::cout << "Adding 10,000,000 numbers in Span of size 10,000" << std::endl;
// Uncomment the next line at your own riks
			// std::cout << very_big << std::endl;
			big.addInRange(vec.begin(), vec.end());
			std::cout << "Range succesfully added" << std::endl;
			big.addInRange(vec.begin(), vec.end());
		} catch (std::exception &except) {
			std::cerr << "Error: " << except.what() << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}
