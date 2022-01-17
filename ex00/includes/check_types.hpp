/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:34:01 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/17 20:44:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TYPES_HPP
# define CHECK_TYPES_HPP
# include <cmath>
# include <climits>
# include <cerrno>
# include "t_data.hpp"

bool	is_int(char const *arg, t_data &data);
bool	is_double(char const *arg, t_data &data);
bool	is_float(char const *arg, t_data &data);
bool	is_char(char const *arg, t_data &data);
void	get_type(char const *arg, t_data &data);

#endif
