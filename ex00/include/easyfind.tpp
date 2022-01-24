/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo <rotrojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:35:07 by bigo              #+#    #+#             */
/*   Updated: 2022/01/24 18:26:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int const &val) {
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return (it);
}
