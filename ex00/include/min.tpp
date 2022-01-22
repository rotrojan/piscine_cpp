/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:56:42 by bigo              #+#    #+#             */
/*   Updated: 2022/01/21 20:18:12 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_TPP
# define MIN_TPP

template <typename T>
T	&min(T &first, T &second) {

	return (first < second ? first : second);
}

#endif
