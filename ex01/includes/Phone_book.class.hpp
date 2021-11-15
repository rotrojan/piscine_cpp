/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:26:34 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/15 22:12:11 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_CLASS_HPP
# define PHONE_BOOK_CLASS_HPP
# include "phone_book.hpp"
# define NB_CONTACT_MAX 8
# define WIDTH_MAX 10

class Phone_book
{
	public:
		Phone_book(void) {};
		~Phone_book(void) {};
		void	add_contact(void);
		void	show_phone_book(void) const;
		Contact	get_contact(int i) const;
	private:
		Contact	contact[NB_CONTACT_MAX];
};

#endif
