/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:56:42 by bigo              #+#    #+#             */
/*   Updated: 2022/01/21 21:02:28 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_TPP
# define MAX_TPP

template <typename T>
T	&max(T &first, T &second) {

	return (first > second ? first : second);
}

#endif
