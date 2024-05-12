/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:12:23 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/26 20:22:34 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	if (c == 0)
	{
		return ((char *)s + ft_strlen(s));
	}
	while (i >= 0)
	{
		if (((unsigned char)c) == s[i])
			return ((char *)(s) + i);
		--i;
	}
	return (0);
}
