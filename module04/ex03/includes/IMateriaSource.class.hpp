/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:50:53 by bigo              #+#    #+#             */
/*   Updated: 2021/12/23 13:21:02 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_CLASS_HPP
# define IMATERIASOURCE_CLASS_HPP
# include "AMateria.class.hpp" 

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {};
		virtual void		learn_materia(AMateria*) = 0;
		virtual AMateria	*create_materia(std::string const & type) = 0;
};

#endif
