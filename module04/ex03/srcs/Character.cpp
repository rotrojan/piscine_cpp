/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:50:53 by bigo              #+#    #+#             */
/*   Updated: 2021/12/24 00:01:46 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < SIZE_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &character)
{
	*this = character;
}

Character::~Character(void)
{
	for (int i = 0; i < SIZE_INVENTORY && this->_inventory[i] != NULL; i++)
		delete this->_inventory[i];
}

Character	&Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < SIZE_INVENTORY; i++)
		{
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const	&Character::get_name() const
{
	return (this->_name);
}

void	Character::equip(AMateria *materia)
{
	if (materia == NULL)
		return ;
	int	i = 0;
	while (i < SIZE_INVENTORY && this->_inventory[i] != NULL)
		i++;
	if (i != SIZE_INVENTORY)
		this->_inventory[i] = materia;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= SIZE_INVENTORY || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx] = NULL;
	while (idx < SIZE_INVENTORY - 1 && this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = this->_inventory[idx + 1];
		++idx;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= SIZE_INVENTORY || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}
