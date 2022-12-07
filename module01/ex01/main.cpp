/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:36:30 by bigo              #+#    #+#             */
/*   Updated: 2021/11/21 18:40:22 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
		return (EXIT_FAILURE);
	int nb_zombies = atoi(av[1]);
	if (nb_zombies < 0)
		return (EXIT_FAILURE);
	Zombie	*zombie = zombieHorde(nb_zombies, av[2]);
	for (int i = 0; i < nb_zombies; i++)
		zombie[i].announce();
	delete [] zombie;
	return (EXIT_SUCCESS);
}
