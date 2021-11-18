/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:08:57 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/17 21:54:26 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

Contact	Phone_book::get_contact(int i) const
{
	return (this->_contact[i]);
}

void	Phone_book::show_phone_book(void) const
{
	std::cout << std::endl << std::setw(WIDTH_MAX) << "INDEX" << "|";
	std::cout << std::setw(WIDTH_MAX) << "NAME" << "|";
	std::cout << std::setw(WIDTH_MAX) << "FIRST NAME" << "|";
	std::cout << std::setw(WIDTH_MAX) << "LAST NAME" << std::endl;
	for (int i = 0; i < this->_nb_contacts; ++i)
	{
		std::cout << std::setw(WIDTH_MAX) << i << "|";
		get_contact(i).show_contact();
	}
}

void	Phone_book::search_contact(void) const
{
	if (this->_nb_contacts == 0)
	{
		std::cout << std::endl << "Your phone book is empty" << std::endl;
		return ;
	}
	int			i;
	std::string	keep_on = "yes";
	while (keep_on == "yes")
	{
		this->show_phone_book();
		std::cout << std::endl << "Which contact do you want to display ?" << std::endl;
		std::cout << "Index: ";
		std::cin >> i;
		if (std::cin.fail() == true || i < 0 || i > this->_nb_contacts)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Incorrect index" << std::endl;
			continue ;
		}
		std::cout << std::endl;
		get_contact(i).print_contact();
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Type \"yes\" if you want to display another contact" << std::endl;
		getline(std::cin, keep_on);
		if (keep_on == "yes")
			continue ;
	}
}

void	Phone_book::add_contact(void)
{
	for (int i = this->_nb_contacts - 1; i > 0; i--)
		this->_contact[i] = this->_contact[i - 1];
	_contact[0].set_contact();
	this->_nb_contacts += this->_nb_contacts == NB_CONTACT_MAX ? 0 : 1;
}
