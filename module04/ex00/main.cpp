/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:05:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/24 00:33:38 by bigo             ###   ########.fr       */
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
	std::cout << "meta is of type " << meta->get_type() << std::endl;
	meta->make_sound();
	std::cout << std::endl;

	const Animal	*dog = new Dog();
	std::cout << "dog is of type " << dog->get_type() << std::endl;
	dog->make_sound();
	std::cout << std::endl;

	const Animal	*cat = new Cat();
	std::cout << "cat is of type " << cat->get_type() << std::endl;
	cat->make_sound();
	std::cout << std::endl;

	delete meta;
	meta = new Dog();
	std::cout << "meta now points on dog" << std::endl;
	meta->make_sound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete meta;
	std::cout << std::endl;

	const WrongAnimal	*wronganimal = new WrongAnimal();
	std::cout << "wronganimal is of type " << wronganimal->get_type() << std::endl;
	wronganimal->make_sound();
	std::cout << std::endl;

	const WrongAnimal	*wrongcat = new WrongCat();
	std::cout << "wrongcat is of type " << wrongcat->get_type() << std::endl;
	wrongcat->make_sound();
	std::cout << std::endl;

	const WrongCat	*fakecat = new WrongCat();
	std::cout << "fakecat is of type " << fakecat->get_type() << std::endl;
	fakecat->make_sound();
	std::cout << std::endl;

	delete fakecat;
	delete wrongcat;
	delete wronganimal;
	return (EXIT_SUCCESS);
}
