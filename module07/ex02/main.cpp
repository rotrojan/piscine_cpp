/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:22:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/22 02:23:08 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.class.tpp"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

int	main(void) {

	{
		Array<char> empty;
		char str[] = "This string is 34 characters long";
		Array<char> array_char(ARRAY_SIZE(str));
		for (unsigned long i = 0; i < ARRAY_SIZE(str); i++)
			array_char[i] = str[i];
		Array<char> copy_char(array_char);
		std::cout << "Initial char *str   = " << str << std::endl;
		std::cout << "Array array_char    = " << array_char << std::endl;
		std::cout << "Copy array_char     = " << copy_char << std::endl;
		try {
			empty = array_char;
		} catch (std::exception &except) {
			std::cerr << "Cannot assign array: " << except.what() << std::endl;
		}
		int index = -1;
		try {
			std::cout << array_char[index];
		} catch (std::exception &except) {
			std::cerr << "Cannot display index " << index << ": " << except.what() << std::endl;
		}
		index = 100;
		try {
			std::cout << array_char[index];
		} catch (std::exception &except) {
			std::cerr << "Cannot display index " << index << ": " << except.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		Array<int> empty;
		int array_int[] = { 12, 134, -12, 66, 42, 0, 22 };
		Array<int> array(ARRAY_SIZE(array_int));
		for (unsigned long i = 0; i < ARRAY_SIZE(array_int); i++)
			array[i] = array_int[i];
		Array<int> copy_int(array);
		std::cout << "Initial int *array = ";
		for (size_t i = 0; i < ARRAY_SIZE(array_int); i++) {
			std::cout << array_int[i];
			if (i != ARRAY_SIZE(array_int))
				std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << "Array array_int    = " << array << std::endl;
		std::cout << "Copy array_int     = " << copy_int << std::endl;
		try {
			empty = array;
		} catch (std::exception &except) {
			std::cerr << "Cannot assign array: " << except.what() << std::endl;
		}
		int index = -1;
		try {
			std::cout << array[index];
		} catch (std::exception &except) {
			std::cerr << "Cannot display index " << index << ": " << except.what() << std::endl;
		}
		index = 100;
		try {
			std::cout << array[index];
		} catch (std::exception &except) {
			std::cerr << "Cannot display index " << index << ": " << except.what() << std::endl;
		}
	}
	return (EXIT_SUCCESS);
}
