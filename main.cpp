/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:05:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/07 23:44:27 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << "dog is of type " << dog->get_type() << std::endl;
	dog->make_sound();
	std::cout << "cat is of type " << cat->get_type() << std::endl;
	cat->make_sound();
	std::cout << "meta is of type " << meta->get_type() << std::endl;
	meta->make_sound();
	delete meta;
	meta = new Dog();
	std::cout << "meta now points on dog" << std::endl;
	meta->make_sound();
	delete dog;
	delete cat;
	delete meta;
	const WrongAnimal	*wronganimal = new WrongAnimal();
	const WrongAnimal	*wrongcat = new WrongCat();
	std::cout << "wrongcat is of type " << wrongcat->get_type() << std::endl;
	wrongcat->make_sound();
	std::cout << "wronganimal is of type " << wronganimal->get_type() << std::endl;
	wronganimal->make_sound();
	delete wrongcat;
	delete wronganimal;
	return (EXIT_SUCCESS);
}
