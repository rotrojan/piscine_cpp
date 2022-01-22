/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:22:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/21 23:39:46 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "iter.tpp"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

int	main(void) {

	char str[] = "THIS IS AN ARRAY OF CHARACTERS";
	char *ptr = str;
	print_array<char>(ptr, ARRAY_SIZE(str));
	iter<char>(*ptr, ARRAY_SIZE(str), &add_thirty_two);
	print_array<char>(ptr, ARRAY_SIZE(str));

	int array[] = { 21, 42, 125, -42, 0, 12 };
	int *int_ptr = array;
	print_array<int>(int_ptr, ARRAY_SIZE(array));
	iter<int>(*array, ARRAY_SIZE(array), &add_thirty_two);
	print_array<int>(int_ptr, ARRAY_SIZE(array));
	return (EXIT_SUCCESS);
}
