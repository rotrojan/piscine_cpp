/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:36:30 by bigo              #+#    #+#             */
/*   Updated: 2021/11/21 16:45:39 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie_stack_0("DeeDee");
	zombie_stack_0.announce();
	Zombie	zombie_stack_1("Markey");
	zombie_stack_1.announce();
	Zombie	zombie_stack_2("Joey");
	zombie_stack_2.announce();
	std::cout << std::endl;

	Zombie	*zombie_heap[3];
	zombie_heap[0] = newZombie("Kurt");
	zombie_heap[0]->announce();
	zombie_heap[1] = newZombie("Chris");
	zombie_heap[1]->announce();
	zombie_heap[2] = newZombie("Dave");
	zombie_heap[2]->announce();
	std::cout << std::endl;

	randomChump("Shavo");
	std::cout << std::endl;
	randomChump("Daron");
	std::cout << std::endl;
	randomChump("Serj");
	std::cout << std::endl;

	delete zombie_heap[0];
	delete zombie_heap[1];
	delete zombie_heap[2];
	std::cout << std::endl;
}
