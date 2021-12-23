/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:05:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/23 11:38:30 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "MateriaSource.class.hpp"
#include "ICharacter.class.hpp"
#include "Character.class.hpp"
#include "AMateria.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"

int	main(void)
{
	IMateriaSource	*src = new MateriaSource();
	src->learn_materia(new Ice());
	src->learn_materia(new Cure());

	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	tmp = src->create_materia("ice");
	me->equip(tmp);
	tmp = src->create_materia("cure");
	me->equip(tmp);
	ICharacter	*bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (EXIT_SUCCESS);
}
