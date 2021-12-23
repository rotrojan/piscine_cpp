/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:50:53 by bigo              #+#    #+#             */
/*   Updated: 2021/12/23 11:46:39 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

Character::Character(std::string name): _name(name)
{
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
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
		for (int i = 0; i < SIZE_INVENTORY && rhs._inventory[i] != NULL; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

std::string const	&Character::get_name() const
{
	return (this->_name);
}

void	Character::equip(AMateria *materia)
{
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
	while (idx < SIZE_INVENTORY - 1 && this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = this->_inventory[idx + 1];
		++idx;
	}
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= SIZE_INVENTORY || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}
