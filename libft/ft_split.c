/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:15:27 by tyavroya          #+#    #+#             */
/*   Updated: 2024/02/27 21:40:43 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_pass_del(char const **s, char del)
{
	while (**s == del && **s)
		(*s)++;
}

static size_t	_len(char const **s, char del)
{
	size_t	len;

	len = 0;
	while (**s && **s != del)
	{
		(*s)++;
		len++;
	}
	return (len);
}

static size_t	_word_count(char const *s, char del)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	_pass_del(&s, del);
	while (*s)
	{
		if (*s != del)
			flag = 1;
		else if (*s == del && flag)
		{
			count++;
			flag = 0;
		}
		s++;
	}
	return (count + flag);
}

static char	**_all(char const *s, char del, size_t count)
{
	char	*p;
	char	**str;
	size_t	len;
	size_t	i;

	i = 0;
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (!str)
		return (0);
	str[count] = 0;
	while (i < count)
	{
		_pass_del(&s, del);
		p = (char *)s;
		len = _len(&s, del);
		str[i] = (char *)malloc(len + 1);
		ft_strlcpy(str[i], p, len + 1);
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (0);
	return (_all(s, c, _word_count(s, c)));
}
// #include <stdio.h>
// #include <stdlib.h>

// static int	_word_count(const char *str, char del)
// {
// 	int	i;
// 	int	count;
// 	int	flag;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	flag = 0;
// 	count = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] != del)
// 			flag = 1;
// 		else if(flag)
// 		{
// 			++count;
// 			flag = 0;
// 		}
// 		++i;
// 	}
// 	return (count + flag);
// }

// static void	_pass_del (char **str, char del)
// {
// 	while (**str == del && **str)
// 		++(*str);
// }

// static void	_init_res(char **to, char *from, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		(*to)[i] = from[i];
// 		++i;
// 	}
// }

// static int	ft_strlen(char *str, char del)
// {
// 	int i;

// 	i = 0;
// 	_pass_del(&str, del);
// 	while (*str != del)
// 	{
// 		++i;
// 		++str;
// 	}
// 	return (i);
// }

// static char	**_allocate (const char *str, char del)
// {
// 	char	**res;
// 	int		i;
// 	int		count;
// 	int		len;

// 	count = _word_count(str, del);
// 	res = (char **) malloc((count + 1)* sizeof(char *));
// 	res[count] = 0;
// 	if (!res)
// 		return (0);
// 	i = 0;
// 	while (i < count)
// 	{
// 		len = ft_strlen(str, del);
// 		res[i] = (char *) malloc(len + 1);
// 		_init_res(res[i], str, len);
// 		++i;
// 	}
// 	return (res);
// }

// char	**ft_split(char const *s, char c)
// {
// 	if (!s)
// 		return (0);
// 	return (_allocate(s, c));
// }

// int main () {
// 	const char* str = "Hello    W  W W W W WW W ";
// 	char **jan = ft_split(str, ' ');
// }
