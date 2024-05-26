/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:27:17 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/26 16:25:01 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	ft_strncmp_pip(char *s1, char *s2, size_t n)
{
	// size_t	tmp;
	int		i;

	i = 0;
	// tmp = n - 1;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		++i;
	}
	if (i == (int)n && (!s1[i] || s1[i] == '\n'))
		return (0);
	return (1);
}

void	create_doc(t_pipex *pipex)
{
	char	*input_line;

	input_line = get_next_line(STDIN_FILENO);
	while (input_line && ((*input_line == '\n' && pipex->limiter)
			|| ft_strncmp_pip(input_line, pipex->limiter,
				ft_strlen(pipex->limiter))))
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
	if (*(av[1]) && !ft_strncmp("here_doc", av[1], ft_strlen(av[1])))
	{
		pipex->doc_flag = 1;
		pipex->limiter = av[2];
	}
	else
		pipex->doc_flag = 0;
}
