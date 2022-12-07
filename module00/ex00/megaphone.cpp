/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:34:31 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/15 15:40:59 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; ++i)
		{
			for (char *ptr = av[i]; *ptr != '\0'; ++ptr)
				*ptr = std::toupper(*ptr);
			std::cout << av[i];
			if (i < ac - 1)
				std::cout << ' ';
			else
				std::cout << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}
