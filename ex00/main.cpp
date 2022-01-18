/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/18 22:15:52 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Literal.class.hpp"

// void	display_char(t_data &data) {
	// enum e_type type = data.type;
	// char c;
	// switch (type) {
		// case CHAR:
			// c = data.val.c;
			// break ;
		// case INT:
			// c = static_cast<char>(data.val.i);
			// break ;
		// case FLOAT:
			// c = static_cast<char>(data.val.f);
			// if (static_cast<float>(c) != data.val.f)
				// data.flags |= IMPOSSIBLECHAR;
			// break ;
		// case DOUBLE:
			// c = static_cast<char>(data.val.d);
			// if (static_cast<double>(c) != data.val.d)
				// data.flags |= IMPOSSIBLECHAR;
			// break ;
		// default:
			// data.flags |= IMPOSSIBLECHAR;
	// }
	// if (type != TYPE_ERROR && (c < ' ' || c > '~'))
		// data.flags |= NONDISPLAYABLECHAR;
	// std::cout << "char: ";
	// if (data.flags & IMPOSSIBLECHAR)
		// std::cout << "impossible";
	// else if (data.flags & NONDISPLAYABLECHAR)
		// std::cout << "Non displayable";
	// else
		// std::cout << "'" << c << "'";
	// std::cout << std::endl;
// }

// void	display_int(t_data &data) {
	// enum e_type type = data.type;
	// int n;
	// switch (type) {
		// case CHAR:
			// n = static_cast<int>(data.val.c);
			// break ;
		// case INT:
			// n = data.val.i;
			// break ;
		// case FLOAT:
			// n = static_cast<int>(data.val.f);
			// if (static_cast<float>(n) != data.val.f)
				// data.flags |= IMPOSSIBLEINT;
			// break ;
		// case DOUBLE:
			// n = static_cast<int>(data.val.d);
			// if (static_cast<double>(n) != data.val.d)
				// data.flags |= IMPOSSIBLEINT;
			// break ;
		// default:
			// data.flags |= IMPOSSIBLEINT;
	// }
	// std::cout << "char: ";
	// if (data.flags & IMPOSSIBLEINT)
		// std::cout << "impossible";
	// else
		// std::cout << n;
	// std::cout << std::endl;
// }

// void	display_data(t_data &data) {
	// // std::cout << "type = " << data.type << std::endl;
	// display_char(data);
	// display_int(data);
// }

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage:" << std::endl;
		std::cerr << av[0] << "<string_to_convert>" << std::endl;
		return (EXIT_FAILURE);
	}
	Literal lit(av[1]);
	lit.print();
	return (EXIT_SUCCESS);
}
