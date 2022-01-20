/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:03:06 by bigo              #+#    #+#             */
/*   Updated: 2022/01/20 19:11:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "serialization.hpp"

int	main(void) {

	Data		data;
	uintptr_t	data_ptr;

	data.str = "This is a string";
	data_ptr = serialize(&data);
	std::cout << &data << std::endl;
	std::cout << "0x" << std::hex << data_ptr << std::endl;

	deserialize(data_ptr);

	std::cout << deserialize(data_ptr)->str << std::endl;
	return (EXIT_SUCCESS);
}
