/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:50:53 by bigo              #+#    #+#             */
/*   Updated: 2021/12/23 15:15:17 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP
# include "IMateriaSource.class.hpp" 
# define NB_MATERIA_MAX 4

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &materiasource);
		MateriaSource	&operator=(MateriaSource const &rhs);
		~MateriaSource(void);
		void		learn_materia(AMateria *materia);
		AMateria	*create_materia(std::string const &type);
	private:
		AMateria	*_learned_materia[NB_MATERIA_MAX];
};

#endif
