/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:21:27 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/26 21:35:08 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_ft_check(size_t count, size_t size)
{
	return (((long long)count < 0 && (long long)size != 0)
		|| ((long long)count != 0 && (long long)size < 0)
		|| ((long long)count >= INT_MAX || (long long)size >= INT_MAX));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (_ft_check(count, size))
		return (0);
	str = malloc(size * count);
	if (str)
		ft_bzero(str, count * size);
	return (str);
}
