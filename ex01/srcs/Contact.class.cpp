/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:06:53 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/17 19:09:17 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

static std::string	format_data(std::string str)
{
	if (str.size() > WIDTH_MAX)
		return (str.substr(0, 9) + '.');
	else
		return (str);
}

void	Contact::show_contact(void) const
{
	std::cout << std::setw(WIDTH_MAX) << format_data(this->first_name) << "|";
	std::cout << std::setw(WIDTH_MAX) << format_data(this->last_name) << "|";
	std::cout << std::setw(WIDTH_MAX) << format_data(this->nickname) << std::endl;
}

void	Contact::print_contact(void) const
{
	std::cout << "First name is: " << this->first_name << std::endl;
	std::cout << "Last name is: " << this->last_name << std::endl;
	std::cout << "Nickname is: " << this->nickname << std::endl;
	std::cout << "Phone number is: " << this->phone_number << std::endl;
	std::cout << "Darkest secret is: \"" << this->darkest_secret << '\"' << std::endl;
}

void	Contact::set_contact(void)
{
	std::cout << std::endl << "Enter first name ?" << std::endl;
	std::getline(std::cin, this->first_name);
	std::cout << "Enter last name ?" << std::endl;
	std::getline(std::cin, this->last_name);
	std::cout << "Enter nickname ?" << std::endl;
	std::getline(std::cin, this->nickname);
	std::cout << "Enter phone number ?" << std::endl;
	std::getline(std::cin, this->phone_number);
	std::cout << "Enter darkest secret ?" << std::endl;
	std::getline(std::cin, this->darkest_secret);
	std::cout << std::endl << "New_contact added" << std::endl;
	this->print_contact();
	std::cout << std::endl;
	return ;
}
