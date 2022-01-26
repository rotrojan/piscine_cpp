/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:22:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/26 15:55:40 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <cstdlib>
#include <iostream>

template <typename T>
void	iter(T const *array, size_t size, void (*function)(T const &)) {
	for (size_t i = 0; i < size; i++) {
		function(array[i]);
	}
}
template <typename T>
void	iter(T *array, size_t size, void (*function)(T &)) {
	for (size_t i = 0; i < size; i++) {
		function(array[i]);
	}
}

template <typename T>
void	add_thirty_two(T &arg) {
	arg += 32;
}

template <typename T>
void	print_array(T const *array, size_t size) {
	size_t i;
	for (i = 0; i < size - 1; i++)
		std::cout << array[i] << " ";
	std::cout << array[i] << std::endl;
}
template <>
void	print_array(char const *array, size_t size) {
	size_t i;
	for (i = 0; i < size; i++)
		std::cout << array[i];
	std::cout << std::endl;
}

#endif
