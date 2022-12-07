/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/20 20:03:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <exception>
#include "Base.class.hpp"
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"

Base	*generate(void) {

	struct timeval seed;
	gettimeofday(&seed, NULL);
	srand(seed.tv_usec);
	int rand_int = rand() % 3;
	if (rand_int == 0) {
		return (new A);
	} else if (rand_int == 1) {
		return (new B);
	} else {
		return (new C);
	}
}

void	identify(Base &p) {

	int count = 0;
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A";
	} catch (std::exception &e) {
		++count;
	}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B";
	} catch (std::exception &e) {
		++count;
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C";
	} catch (std::exception &e) {
		++count;
	}
	if (count == 3)
		std::cout << "Class not known";
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "A";
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B";
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C";
	} else
		std::cout << "Class not known";
}

int	main(void) {

	Base	*b;

	for (int i = 0; i < 10; i++) {
		b = generate();
		identify(b);
		std::cout << " ";
		identify(*b);
		std::cout << std::endl;
		delete b;
	}

	return (EXIT_SUCCESS);
}
