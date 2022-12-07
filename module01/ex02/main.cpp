/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:36:30 by bigo              #+#    #+#             */
/*   Updated: 2021/11/21 23:46:31 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

int	main(void)
{
	std::string const	string = "HI THIS IS BRAIN";
	std::string const	*stringPTR = &string;
	std::string const	&stringREF = string;

	std::cout << "string address      = " << &string << std::endl;
	std::cout << "stringPTR points to = " << stringPTR << std::endl;
	std::cout << "stringREF refers to = " << &stringREF << std::endl << std::endl;
	std::cout << "string              = " << string << std::endl;
	std::cout << "*stringPTR          = " << *stringPTR << std::endl;
	std::cout << "stringREF           = " << stringREF << std::endl;
	return (EXIT_SUCCESS);
}
