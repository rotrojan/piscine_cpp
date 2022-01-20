/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:21:16 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/20 17:33:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP
# include <stdint.h>
# include <string>

typedef struct s_data {
	std::string	str;
}	Data;


Data		*deserialize(uintptr_t raw);
uintptr_t	serialize(Data *ptr);

#endif
