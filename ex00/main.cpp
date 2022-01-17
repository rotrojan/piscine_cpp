/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/17 23:06:32 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "t_data.hpp"
#include "check_types.hpp"

void display_char(t_data &data) {
	enum e_type type = data.type;
	char c;

	if (type == CHAR) {
		c = data.val.c;
	} else if (type == INT) {
		c = static_cast<char>(data.val.i);
	} else if (type == FLOAT) {
		c = static_cast<char>(data.val.f);
		if (static_cast<float>(c) != data.val.f)
			data.flags |= IMPOSSIBLECHAR;
	} else if (type == DOUBLE) {
		c = static_cast<char>(data.val.d);
		if (static_cast<double>(c) != data.val.d)
			data.flags |= IMPOSSIBLECHAR;
	} else
		data.flags |= IMPOSSIBLECHAR;

	if (type != TYPE_ERROR && (c < ' ' || c > '~'))
		data.flags |= NONDISPLAYABLECHAR;

	std::cout << "char: ";

		if (data.flags & IMPOSSIBLECHAR)
			std::cout << "impossible";
		else if (data.flags & NONDISPLAYABLECHAR)
			std::cout << "Non displayable";
		else
			std::cout << "'" << c << "'";

	std::cout << std::endl;
}

void	display_data(t_data &data) {
	std::cout << "type = " << data.type << std::endl;
	display_char(data);
}

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage:" << std::endl;
		std::cerr << av[0] << "<string_to_convert>" << std::endl;
		return (EXIT_FAILURE);
	}
	t_data data;
	get_type(av[1], data);
	display_data(data);
	return (EXIT_SUCCESS);
}
