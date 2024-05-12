/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:54 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/26 18:57:48 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	if (n == 0)
		return (0);
	tmp = n - 1;
	while (*s1 && *s2 && tmp)
	{
		if (*s1 != *s2)
			break ;
		++s1;
		++s2;
		--tmp;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
