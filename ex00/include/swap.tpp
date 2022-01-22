/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:56:42 by bigo              #+#    #+#             */
/*   Updated: 2022/01/21 21:01:08 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_TPP
# define SWAP_TPP

template <typename T>

void	swap(T &first, T &second) {

	T	tmp = first;
	first = second;
	second = tmp;
}

#endif
