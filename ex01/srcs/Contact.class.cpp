/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:06:53 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/15 22:05:52 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

void	Contact::show_contact(void) const
{
	std::cout << this->first_name << ' ';
	std::cout << this->last_name << ' ';
	std::cout << this->nickname << std::endl;
}

void	Contact::print_new_contact(void) const
{
	std::cout << "New_contact added" << std::endl;
	std::cout << "Your first name is " << this->first_name << std::endl;
	std::cout << "Your last name is " << this->last_name << std::endl;
	std::cout << "Your nickname is " << this->nickname << std::endl;
	std::cout << "Your phone number is " << this->phone_number << std::endl;
	std::cout << "Your phone darkest secret is " << this->darkest_secret << std::endl;
}

void	Contact::set_contact(void)
{
	std::cout << "What is your first name ?" << std::endl;
	std::cin >> this->first_name;
	std::cout << "What is your last name ?" << std::endl;
	std::cin >> this->last_name;
	std::cout << "What is your nickname ?" << std::endl;
	std::cin >> this->nickname;
	std::cout << "What is your phone number ?" << std::endl;
	std::cin >> this->phone_number;
	std::cout << "What is your darkest secret ?" << std::endl;
	std::getline(std::cin, this->darkest_secret);
	std::cout << std::endl;
	this->print_new_contact();
	return ;
}
