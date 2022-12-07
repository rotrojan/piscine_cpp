/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone_book.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:26:34 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/17 21:52:41 by bigo             ###   ########.fr       */
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
		Phone_book(void): _nb_contacts(0) {};
		~Phone_book(void) {};
		Contact	get_contact(int i) const;
		void	show_phone_book(void) const;
		void	search_contact(void) const;
		void	add_contact(void);
	private:
		Contact	_contact[NB_CONTACT_MAX];
		int		_nb_contacts;
};

#endif
