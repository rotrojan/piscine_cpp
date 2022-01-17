/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:33:24 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/17 23:01:59 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_types.hpp"

bool	is_int(char const *arg, t_data &data) {
	char *end_ptr = NULL;
	long int res = strtol(arg, &end_ptr, 10);
	if (*end_ptr != '\0' || errno != 0 || res > INT_MAX || res < INT_MIN)
		return (false);
	if (res < CHAR_MIN || res > CHAR_MAX)
		data.flags |= IMPOSSIBLECHAR;
	data.val.i = static_cast<int>(res);
	data.type = INT;
	return (true);
}

bool	is_double(char const *arg, t_data &data) {
	char *end_ptr = NULL;
	double res = strtod(arg, &end_ptr);
	if (*end_ptr != '\0' || errno != 0 || res == HUGE_VAL)
		return (false);
	if (strtof(arg, NULL) == HUGE_VALF)
		data.flags |= IMPOSSIBLEFLOAT | IMPOSSIBLEINT | IMPOSSIBLECHAR;
	data.val.d = res;
	data.type = DOUBLE;
	long int tmp = static_cast<long int>(data.val.f);
	if (tmp < INT_MIN || tmp > INT_MAX)
		data.flags |= IMPOSSIBLEINT | IMPOSSIBLECHAR;
	return (true);
}

bool	is_float(char const *arg, t_data &data) {
	char *end_ptr = NULL;
	float res = strtof(arg, &end_ptr);
	if (*end_ptr != 'f' || *(end_ptr + 1) != '\0' || end_ptr - arg <= 0
			|| res == HUGE_VALF || errno != 0)
		return (false);
	data.val.f = res;
	data.type = FLOAT;
	long int tmp = static_cast<long int>(data.val.f);
	if (tmp < INT_MIN || tmp > INT_MAX)
		data.flags |= IMPOSSIBLEINT | IMPOSSIBLECHAR;
	return (true);
}
bool	is_char(char const *arg, t_data &data) {
	char c = arg[0];
	if (arg[1] != '\0' || c < ' ' || c > '~') // range of printable ascii characters for c
		return (false);
	data.val.c = c;
	data.type = CHAR;
	return (true);
}

void	get_type(char const *arg, t_data &data) {
	data.flags = 0;
	if (is_int(arg, data) == false
		&& is_double(arg, data) == false
		&& is_float(arg, data) == false
		&& is_char(arg, data) == false)
		data.type = TYPE_ERROR;
}

