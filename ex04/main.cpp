/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:36:19 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/24 01:50:39 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <filesystem>

bool	check_errors(int ac, char **av)
{
	bool	ret = true;
	if (ac != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		ret = false;
	}
	else if (*av[1] == '\0')
	{
		std::cout << "Error: you must specify a file name" << std::endl;
		ret = false;
	}
	else if (*av[2] == '\0')
	{
		std::cout << "Error: he string to match cannot be empty" << std::endl;
		ret = false;
	}
	if (ret == false)
		std::cout << "Usage: ./replace <file> <string1> <string2>" << std::endl;
	return (ret);
}

bool	from_file_to_string(char *file_name, std::string &file_string)
{
	std::stringstream	file_content;
	std::ifstream		input_file_stream(file_name);

	if (input_file_stream.good() == false)
	{
		std::cout << "Error: file does not exist" << std::endl;
		return (false);
	}
	file_content << input_file_stream.rdbuf();
	input_file_stream.close();
	file_string = file_content.str();
	return (true);
}

void	from_string_to_file(std::string file_string, std::string file_name)
{
	file_name += ".replace";
	std::ofstream	output_file_stream(file_name.c_str());
	output_file_stream << file_string;
	output_file_stream.close();
}

void	replace(std::string &file_string, std::string str1, char *str2)
{
	size_t	len = str1.length();
	size_t	found;

	while ((found = file_string.find(str1)) != std::string::npos)
	{
		file_string.erase(found, len);
		file_string.insert(found, str2);
		found = file_string.find(str1);
	}
}

int	main(int ac, char **av)
{
	if (check_errors(ac, av) == false)
		return (EXIT_FAILURE);
	else
	{
		std::string	file_string;
		if (from_file_to_string(av[1], file_string) == false)
			return (EXIT_FAILURE);
		if (std::string(av[2]) != std::string(av[3]))
			replace(file_string, std::string(av[2]), av[3]);
		from_string_to_file(file_string, std::string(av[1]));
	}
	return (EXIT_SUCCESS);
}
