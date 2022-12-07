/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:26:17 by bigo              #+#    #+#             */
/*   Updated: 2021/11/22 19:06:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

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
