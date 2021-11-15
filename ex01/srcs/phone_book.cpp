/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:52:36 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/15 22:15:42 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int	main(void)
{
	Phone_book	phone_book;
	std::string		input;

	std::cout << "Welcome to the phone book" << std::endl;
	while (input != "EXIT")
	{
		std::cout << "What do you want to do (SEARCH, ADD or EXIT) ?" << std::endl;
		getline(std::cin, input);
		if (input == "ADD")
			phone_book.add_contact();
		else if (input == "SEARCH")
			phone_book.show_phone_book();
		else
			std::cout << "Invalid request" << std::endl;
	}
	std::cout << "Thank you for consulting the " << std::endl;
	return (EXIT_SUCCESS);
}
