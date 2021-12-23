/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:05:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/24 00:02:41 by bigo             ###   ########.fr       */
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
	std::cout << std::endl;

	me->use(3, *me);
	me->use(42, *me);
	me->use(-42, *bob);
	me->unequip(1);
	delete tmp;
	me->use(0, *bob);

	delete bob;
	delete me;
	std::cout << std::endl;

	Character	cloud;
	cloud.equip(src->create_materia("ice"));
	cloud.equip(src->create_materia("fire"));
	cloud.equip(src->create_materia("cure"));
	Character	cloud2(cloud);
	cloud2.use(0, cloud);
	cloud2.use(1, cloud);
	delete src;
	return (EXIT_SUCCESS);
}
