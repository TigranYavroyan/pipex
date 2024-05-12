/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:07:14 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/28 20:21:03 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (NULL);
	i = 0;
	res = ft_strdup((char *)s);
	if (!res)
		return (NULL);
	while (res[i] != '\0')
	{
		res[i] = f(i, res[i]);
		++i;
	}
	return (res);
}
