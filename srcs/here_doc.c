/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:27:17 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/12 21:10:49 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	ft_strncmp_pip(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	if (n != ft_strlen(s1) - 1)
		return (1);
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

void	create_doc(t_pipex *pipex)
{
	char	*input_line;

	input_line = get_next_line(STDIN_FILENO);
	while ((*input_line == '\n' && pipex->limiter) || ft_strncmp_pip(input_line,
			pipex->limiter, ft_strlen(pipex->limiter)))
	{
		ft_putstr_fd(input_line, pipex->infile);
		free(input_line);
		input_line = get_next_line(STDIN_FILENO);
	}
	free(input_line);
	close(pipex->infile);
}

void	check_here_doc(t_pipex *pipex, char **av)
{
	if (!ft_strncmp("here_doc", av[1], ft_strlen(av[1])))
	{
		pipex->doc_flag = 1;
		pipex->limiter = av[2];
	}
	else
		pipex->doc_flag = 0;
}

