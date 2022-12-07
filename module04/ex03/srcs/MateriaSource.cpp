/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:50:53 by bigo              #+#    #+#             */
/*   Updated: 2021/12/23 22:37:57 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.class.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < NB_MATERIA_MAX; i++)
		this->_learned_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &materiasource)
{
	*this = materiasource;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < NB_MATERIA_MAX && this->_learned_materia[i] != NULL; i++)
		delete this->_learned_materia[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
		for (int i = 0; i < NB_MATERIA_MAX; i++)
		{
			if (rhs._learned_materia[i] != NULL)
				this->_learned_materia[i] = rhs._learned_materia[i]->clone();
			else
				this->_learned_materia[i] = NULL;
		}
	return (*this);
}

void	MateriaSource::learn_materia(AMateria *materia)
{
	for (int i = NB_MATERIA_MAX - 1; i > 0; i--)
		this->_learned_materia[i] = this->_learned_materia[i - 1];
	this->_learned_materia[0] = materia;
}

AMateria	*MateriaSource::create_materia(const std::string &type)
{
	int	i = 0;

	while (this->_learned_materia[i] != NULL
		&& this->_learned_materia[i]->get_type() != type
		&& i < NB_MATERIA_MAX)
		++i;
	if (i == NB_MATERIA_MAX || this->_learned_materia[i] == NULL)
		return (NULL);
	return (this->_learned_materia[i]->clone());
}
