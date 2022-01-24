/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/24 23:34:02 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include <sys/time.h>
#include "Span.hpp"
#define ARRAY_SIZE(x) sizeof(x) / sizeof(*x)


static int	random_nb() {

	static int seed_is_init __attribute__((unused)) = (srand(time(NULL)), 0);
	return (rand() % INT_MAX);
}

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span span(100000);
	std::fill(span.getData().begin(), span.getData().end(), random_nb());
	Span respan(100000);
	respan.addInRange(span.getData().begin(), span.getData().end());
	std::cout << respan << std::endl;
	return (EXIT_SUCCESS);
}
