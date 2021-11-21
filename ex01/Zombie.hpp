/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:26:17 by bigo              #+#    #+#             */
/*   Updated: 2021/11/21 22:30:43 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class	Zombie
{
	public:
		Zombie();
		~Zombie();
		void		announce(void);
		void		set_name(std::string);
	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
