/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:14:14 by bigo              #+#    #+#             */
/*   Updated: 2021/11/24 19:31:50 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <cstdlib>
#include <iostream>

enum e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./karen <level>" << std::endl;
		return (EXIT_FAILURE);
	}
	int			i;
	Karen		karen;
	std::string	word_array[NB_LEVELS] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (i = 0; i < NB_LEVELS; i++)
		if ((av[1]) == word_array[i])
			break ;
	switch (i)
	{
		case DEBUG:
			karen.complain("DEBUG");
			std::cout << std::endl;
		case INFO:
			karen.complain("INFO");
			std::cout << std::endl;
		case WARNING:
			karen.complain("WARNING");
			std::cout << std::endl;
		case ERROR:
			karen.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
	return (EXIT_SUCCESS);
}
