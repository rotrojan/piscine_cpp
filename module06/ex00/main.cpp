/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/20 17:16:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Literal.class.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage:" << std::endl;
		std::cerr << av[0] << "<string_to_convert>" << std::endl;
		return (EXIT_FAILURE);
	}
	Literal lit(av[1]);
	lit.print();
	return (EXIT_SUCCESS);
}
