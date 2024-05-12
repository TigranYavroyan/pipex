/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:32:33 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/28 18:35:36 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnum(int num, int fd)
{
	char	current;

	current = num + '0';
	write(fd, &current, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = (-1) * n;
	}
	if (n < 10)
	{
		ft_putnum(n, fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putnum(n % 10, fd);
}
