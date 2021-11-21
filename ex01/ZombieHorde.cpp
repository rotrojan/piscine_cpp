/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:49:40 by bigo              #+#    #+#             */
/*   Updated: 2021/11/21 22:10:39 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie				*zombie = new Zombie[N];
	std::stringstream	strstream;

	for (int i = 0; i < N; i++)
	{
		strstream << i;
		zombie[i].set_name(name + strstream.str()); 
		strstream.clear(); // clear the flags of the strstream
		strstream.str(std::string()); // clear the content of the strstream
	}
	return (zombie);
}
