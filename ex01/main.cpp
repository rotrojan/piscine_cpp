/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:22:10 by bigo              #+#    #+#             */
/*   Updated: 2022/01/26 16:04:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "iter.hpp"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

int	main(void) {

	char str[] = "THIS IS AN ARRAY OF CHARACTERS";
	char *ptr = str;
	print_array<char>(ptr, ARRAY_SIZE(str));
	iter<char>(ptr, ARRAY_SIZE(str), &add_thirty_two);
	print_array<char>(ptr, ARRAY_SIZE(str));

	int array[] = { 21, 42, 125, -42, 0, 12 };
	int *int_ptr = array;
	print_array<int>(int_ptr, ARRAY_SIZE(array));
	iter<int>(array, ARRAY_SIZE(array), &add_thirty_two);
	print_array<int>(int_ptr, ARRAY_SIZE(array));
	return (EXIT_SUCCESS);
}

// The following main is the one provided by the evaluation scale.
/*
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
	return 0;
}
*/
