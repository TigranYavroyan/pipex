/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:24:00 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/26 20:44:13 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	if ((!haystack || !needle) && !len)
		return (0);
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i + n_len <= len)
	{
		if (!ft_strncmp(haystack + i, needle, n_len) && i + n_len <= h_len)
			return ((char *)haystack + i);
		++i;
	}
	return (0);
}
