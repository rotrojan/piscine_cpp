/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:38:29 by rotrojan          #+#    #+#             */
/*   Updated: 2022/01/17 20:39:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_HPP
# define T_DATA_HPP
# define NONDISPLAYABLECHAR 1<<0
# define IMPOSSIBLECHAR 1<<1
# define IMPOSSIBLEINT 1<<2
# define IMPOSSIBLEFLOAT 1<<2

enum e_type {
	TYPE_ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	TYPE_MAX
};

union u_val {
	char	c;
	int		i;
	float	f;
	double	d;
};

typedef struct s_data {
	union u_val	val;
	enum e_type	type;
	char flags;
} t_data;

#endif
