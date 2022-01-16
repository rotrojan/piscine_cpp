/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/15 23:06:25 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Literal.class.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage:" << std::endl;
		std::cout << av[0] << "<string_to_convert>" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string	arg(av[1]);
	Literal lit(arg);
	std::cout << "double: " << lit.to_double() << std::endl;
	return (EXIT_SUCCESS);
}
