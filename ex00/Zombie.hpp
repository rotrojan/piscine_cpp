/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:26:17 by bigo              #+#    #+#             */
/*   Updated: 2021/11/21 22:17:57 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void) const;
	private:
		std::string const	_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
