/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/11 22:31:36 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP
# include <iostream>
# define NB_IDEAS_MAX 100

class	Brain
{
	public:
		Brain(void);
		Brain(Brain const &brain);
		~Brain(void);
		Brain		&operator=(Brain const &rhs);
		std::string const	to_str(void) const;
	protected:
		std::string	_ideas[NB_IDEAS_MAX];
};

std::ostream	&operator<<(std::ostream &ostream, Brain const &rhs);

#endif
