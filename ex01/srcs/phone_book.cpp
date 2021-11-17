/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:52:36 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/17 19:03:21 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int	main(void)
{
	Phone_book		phone_book;
	std::string		input;

	std::cout << "Welcome to the phone book" << std::endl;
	std::cout << std::endl;
	while (true)
	{
		std::cout << "What do you want to do (SEARCH, ADD or EXIT) ?" << std::endl;
		getline(std::cin, input);
		if (input == "ADD")
			phone_book.add_contact();
		else if (input == "SEARCH")
			phone_book.search_contact();
		else if (input == "EXIT" || std::cin.eof() == true)
			break ;
		else
			std::cout << "Invalid request" << std::endl << std::endl;
	}
	std::cout << std::endl << "Thank you for consulting the phone book" << std::endl;
	std::cout << "All your contacts will be lost ... how sad" << std::endl;
	return (EXIT_SUCCESS);
}
