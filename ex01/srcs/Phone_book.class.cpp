/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:08:57 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/15 22:12:11 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

Contact	Phone_book::get_contact(int i) const
{
	return (this->contact[i]);
}

void	Phone_book::show_phone_book(void) const
{
	std::cout << std::setw(WIDTH_MAX);
	for (int i = 0; i < NB_CONTACT_MAX; ++i)
	{
		std::cout << i << ' ';
		get_contact(i).show_contact();
	}

}

void	Phone_book::add_contact(void)
{
	for (int i = 0; i < NB_CONTACT_MAX - 1; ++i)
		this->contact[i] = this->contact[i + 1];
	contact[0].set_contact();
}
